import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

class tarea_8 {
 public static void main(String[] args) {
  try {
   ArrayList<Instruccion> instrucciones = RutinasInterprete.preprocesa(System.in);
   RutinasInterprete.ejecuta(instrucciones, System.out);
  } catch (Exception ex) {
   System.out.println(ex.getMessage());
  }
 }
}

abstract class Instruccion {
 protected int numero_instruccion;

 public Instruccion(int numero) {
  numero_instruccion = numero;
 }

 public abstract void ejecuta(TreeMap<String, Integer> tabla, OutputStream salida) throws Exception;
}

class InstruccionAsignacion extends Instruccion {
 String var;
 int val;

 public InstruccionAsignacion(int numero, String v, int valor) {
  super(numero);
  var = v;
  val = valor;
 }

 @Override
 public void ejecuta(TreeMap<String, Integer> tabla, OutputStream salida) throws Exception {
  tabla.put(var, val);
 }
}

class InstruccionImprime extends Instruccion {
 String var;

 public InstruccionImprime(int numero, String v) {
  super(numero);
  var = v;
 }

 @Override
 public void ejecuta(TreeMap<String, Integer> tabla, OutputStream salida) throws Exception {
  Integer valor = tabla.get(var);
  if (valor == null) {
   throw new Exception(numero_instruccion + ": Variable no existe");
  }
  PrintStream ps = new PrintStream(salida);
  ps.println(valor);
 }
}

class InstruccionAsignacionCondicional extends Instruccion {
 String condition;
 String var;
 int val;

 public InstruccionAsignacionCondicional(int numero, String cond, String v, int valor) {
  super(numero);
  condition = cond;
  var = v;
  val = valor;
 }

 @Override
 public void ejecuta(TreeMap<String, Integer> tabla, OutputStream salida) throws Exception {
  Integer condVal = tabla.get(condition);
  if (condVal == null) {
   throw new Exception(numero_instruccion + ": Variable no existe");
  }
  if (condVal != 0) {
   tabla.put(var, val);
  }
 }
}

class RutinasInterprete {
 public static ArrayList<Instruccion> preprocesa(InputStream entrada) {
  ArrayList<Instruccion> instrucciones = new ArrayList<Instruccion>();
  Scanner sc = new Scanner(entrada);
  int numero = 1;
  while (sc.hasNextLine()) {
   String linea = sc.nextLine();
   String[] tokens = linea.split(" ");
   if (tokens[0].equals("ASIGNA")) {
    String v = tokens[1];
    int valor = Integer.parseInt(tokens[2]);
    instrucciones.add(new InstruccionAsignacion(numero, v, valor));
   } else if (tokens[0].equals("IMPRIME")) {
    String v = tokens[1];
    instrucciones.add(new InstruccionImprime(numero, v));
   } else if (tokens[0].equals("ASIGNA_CONDICIONAL")) {
    String cond = tokens[1];
    String v = tokens[2];
    int valor = Integer.parseInt(tokens[3]);
    instrucciones.add(new InstruccionAsignacionCondicional(numero, cond, v, valor));
   }
   numero++;
  }
  sc.close();
  return instrucciones;
 }

 public static void ejecuta(ArrayList<Instruccion> instrucciones, OutputStream salida)
   throws Exception {
  TreeMap<String, Integer> tabla = new TreeMap<String, Integer>();
  for (int i = 0; i < instrucciones.size(); i++) {
   instrucciones.get(i).ejecuta(tabla, salida);
  }
 }
}