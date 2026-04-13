import java.io.IOException;

class EntradaEstandar implements FlujoEntrada {
  public void consume() throws IOException {
    {
      if (System.in.available() > 0)
        System.in.read();
    }
  }

  public int examina() throws IOException {
    return System.in.read();
  }
}

class EntradaCadena implements FlujoEntrada {
  private String datos;
  private int pos;

  public EntradaCadena(String d) {
    this.datos = d;
    this.pos = 0;
  }

  @Override
  public int examina() {
    if (pos >= datos.length()) {
      return -1;
    }
    return datos.charAt(pos);
  }

  @Override
  public void consume() {
    if (pos < datos.length()) {
      pos++;
    }
  }
}

class RutinasEntrada {
  public static int leeEntero(FlujoEntrada ent) throws Exception {
    while (true) {
      int c = ent.examina();
      if (c == -1)
        throw new Exception("fin de flujo antes de leer entero");
      if (c != ' ' && c != '\n')
        break;
      ent.consume();
    }
    int primero = ent.examina();
    if (primero < '0' || primero > '9')
      throw new Exception("no se encontró un entero válido");

    int acum = 0;
    while (true) {
      int c = ent.examina();
      if (c == -1 || c < '0' || c > '9')
        break;
      acum = acum * 10 + (c - '0');
      ent.consume();
    }

    return acum;
  }
}

interface FlujoEntrada {
  int examina() throws IOException;

  void consume() throws IOException;
}

class Main {
  public static void main(String[] args) throws Exception {
    var ent1 = new EntradaCadena("5 7");
    int a = RutinasEntrada.leeEntero(ent1);
    int b = RutinasEntrada.leeEntero(ent1);
    var ent2 = new EntradaCadena(" 123 456");
    int x = RutinasEntrada.leeEntero(ent2);
    int y = RutinasEntrada.leeEntero(ent2);
    System.out.printf("%d %d\n", a, b);
    System.out.printf("%d %d\n", x, y);
  }
}