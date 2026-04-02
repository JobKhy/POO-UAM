class instruccion
{
protected:
 int numero_instruccion;

public:
 explicit instruccion(int numero)
 {
  numero_instruccion = numero;
 }
 virtual ~instruccion() = default;
 virtual void ejecuta(std::map<std::string, int> &tabla_variables, std::ostream &salida) const = 0;
};

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <sstream>
#include <stdexcept>

class instruccion_asignacion : public instruccion
{
 std::string var;
 int val;

public:
 instruccion_asignacion(int numero, std::string v, int valor)
     : instruccion(numero), var(std::move(v)), val(valor) {}

 void ejecuta(std::map<std::string, int> &tabla_variables, std::ostream &) const override
 {
  tabla_variables[var] = val;
 }
};

class instruccion_asignacion_condicional : public instruccion
{
 std::string condition;
 std::string var;
 int val;

public:
 instruccion_asignacion_condicional(int numero, std::string cond, std::string v, int valor)
     : instruccion(numero), condition(std::move(cond)), var(std::move(v)), val(valor) {}

 void ejecuta(std::map<std::string, int> &tabla_variables, std::ostream &) const override
 {
  auto it = tabla_variables.find(condition);
  if (it == tabla_variables.end())
   throw std::runtime_error(std::to_string(numero_instruccion) + ": Variable no existe");
  if (it->second != 0)
   tabla_variables[var] = val;
 }
};

class instruccion_impresion : public instruccion
{
 std::string var;

public:
 instruccion_impresion(int numero, std::string v)
     : instruccion(numero), var(std::move(v)) {}

 void ejecuta(std::map<std::string, int> &tabla_variables, std::ostream &salida) const override
 {
  auto it = tabla_variables.find(var);
  if (it == tabla_variables.end())
   throw std::runtime_error(std::to_string(numero_instruccion) + ": Variable no existe");
  salida << it->second << "\n";
 }
};

std::vector<std::shared_ptr<instruccion>> preprocesa(std::istream &entrada)
{
 std::vector<std::shared_ptr<instruccion>> res;
 std::string line;
 int num = 1;

 while (std::getline(entrada, line))
 {
  std::istringstream ss(line);
  std::string tipo;
  ss >> tipo;

  if (tipo == "ASIGNA")
  {
   std::string var;
   int val;
   ss >> var >> val;
   res.push_back(std::make_shared<instruccion_asignacion>(num, var, val));
  }
  else if (tipo == "ASIGNA_CONDICIONAL")
  {
   std::string cond, var;
   int val;
   ss >> cond >> var >> val;
   res.push_back(std::make_shared<instruccion_asignacion_condicional>(num, cond, var, val));
  }
  else if (tipo == "IMPRIME")
  {
   std::string var;
   ss >> var;
   res.push_back(std::make_shared<instruccion_impresion>(num, var));
  }

  num++;
 }

 return res;
}

void ejecuta(const std::vector<std::shared_ptr<instruccion>> &instrucciones, std::ostream &salida)
{
 std::map<std::string, int> tabla;
 for (const auto &instr : instrucciones)
  instr->ejecuta(tabla, salida);
}

int main()
try
{
 auto instrucciones = preprocesa(std::cin);
 ejecuta(instrucciones, std::cout);
}
catch (const std::exception &ex)
{
 std::cout << ex.what();
}