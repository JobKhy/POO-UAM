struct flujo_entrada
{
  virtual ~flujo_entrada() = default;
  virtual int examina() const = 0;
  virtual void consume() = 0;
};

#include <iostream>
#include <string>
#include <stdexcept>

class entrada_estandar : public flujo_entrada
{
public:
  entrada_estandar() = default;

  int examina() const override
  {
    return std::cin.peek();
  }

  void consume() override
  {
    if (std::cin.peek() != EOF)
      std::cin.ignore();
  }
};

class entrada_cadena : public flujo_entrada
{
  std::string datos_;
  std::string::size_type pos_;

public:
  explicit entrada_cadena(const std::string &s)
      : datos_(s), pos_(0) {}

  int examina() const override
  {
    if (pos_ >= datos_.size())
      return EOF;
    return static_cast<int>(static_cast<unsigned char>(datos_[pos_]));
  }

  void consume() override
  {
    if (pos_ < datos_.size())
      ++pos_;
  }
};

flujo_entrada &operator>>(flujo_entrada &ent, int &v)
{
  while (true)
  {
    int c = ent.examina();
    if (c == EOF)
      throw std::runtime_error("fin de flujo antes de leer entero");
    if (c != ' ' && c != '\n')
      break;
    ent.consume();
  }

  bool negativo = false;
  {
    int c = ent.examina();
    if (c == '+')
    {
      ent.consume();
    }
    else if (c == '-')
    {
      negativo = true;
      ent.consume();
    }
  }

  int c = ent.examina();
  if (c == EOF || !std::isdigit(static_cast<unsigned char>(c)))
    throw std::runtime_error("no se encontró un entero válido");

  long long acum = 0;
  while (true)
  {
    c = ent.examina();
    if (c == EOF || !std::isdigit(static_cast<unsigned char>(c)))
      break;
    acum = acum * 10 + (c - '0');
    ent.consume();
  }

  v = static_cast<int>(negativo ? -acum : acum);
  return ent;
}

int main()
{
  entrada_estandar ent1;
  int a, b;
  ent1 >> a >> b;
  entrada_cadena ent2(" 123 456");
  int x, y;
  ent2 >> x >> y;
  std::cout << a << " " << b << "\n";
  std::cout << x << " " << y << "\n";
}
