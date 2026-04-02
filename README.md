# Códigos clase de POO UAM-A

## Ing. en computación

---

La intención de este repositorio es almacenar las tareas y trabajos realizados en la materia de POO de la UAM-A.

## Listado de tareas

1. [Tarea 1](#tarea-1)
2. [Tarea 2](#tarea-2)
3. [Tarea 3](#tarea-3)
4. [Tarea 4](#tarea-4)
5. [Tarea 5](#tarea-5)
6. [Tarea 6](#tarea-6)

### Tarea 1:

Implementa un tipo de dato fraccion que modele una fracción o número racional. Tanto el numerador como el
denominador de la fracción deben representarse por variables int como sigue:

```cpp
struct fraccion {
int num, den;
};
fraccion a;
a.num = 1;
a.den = 2; // a vale ½
fraccion b = { 1, 2 }; // b vale ½ también
fraccion c = fraccion(1, 2); // c vale ½ también
fraccion d(1, 2); // d vale ½ también
fraccion e = { .num = 1, .den = 2 }; // e vale ½ también
```

Las operaciones que se deben implementar son:

- Suma de fracciones
- Resta de fracciones
- Multiplicación de fracciones
- División de fracciones
- Identidad aritmética.
- Negación aritmética.
- Reciproco de una fracción.
- Comparación de fracciones (igualdad, menor que, mayor que, menor o igual que, mayor o igual que).
- Conversión a flotante.
- Impresión y lectura de fracciones.

### Tarea 2:

Implementa un tipo de dato conjunto que modele un conjunto que puede contener los enteros del 0 al 99.

Las operaciones disponibles deben ser las siguientes.

- Inicialización por defecto.
- Función miembro bool inserta(int v);
- Función miembro bool elimina(int v);
- Función miembro int size( ) const;
- Función miembro int operator[](int i) const;
- Funciones no miembro operator== y operator!=
- Copia y asignación

#### Ejemplo de uso:

```cpp
int main( ) {
conjunto c;
bool b1 = c.inserta(3);
bool b2 = c.inserta(1);
bool b3 = c.inserta(3);
std::cout << b1 << " "
<< b2 << " "
<< b3 << "\n";
std::cout << c.size( ) << "\n";
for (int i = 0; i < c.size( ); ++i) {
std::cout << c[i] << " ";
}
std::cout << "\n";
conjunto d = c;
std::cout << (c == d) << "\n";
}
```

#### Salida:

```
1 1 0
2
1 3
1
```

### Tarea 3:

Implementa un tipo de dato `matriz` que modele una matriz de enteros de dimensiones arbitrarias con manejo manual de memoria dinámica.

Las operaciones que se deben implementar son:

- Constructor con dimensiones (`rows`, `cols`), lanza `std::invalid_argument` si alguna dimensión es negativa.
- Constructor de copia (deep copy).
- Destructor que libera la memoria.
- Operador de asignación.
- Función miembro `int filas() const`.
- Función miembro `int columnas() const`.
- `operator()(int i, int j)` para acceso por referencia (versión mutable y constante), lanza `std::out_of_range` si el índice está fuera de rango.

#### Ejemplo de uso:

```cpp
int main() {
    matriz a(5, 3);
    matriz b = a;
    a(0, 1) = 7;
    std::cout << a(0, 1) << "\n"; // 7
    std::cout << b(0, 1) << "\n"; // 0
}
```

#### Salida:

```
7
0
```

### Tarea 4:

Implementa una jerarquía de clases para modelar flujos de entrada genéricos. Se define una clase base abstracta `flujo_entrada` y dos implementaciones concretas.

Las clases que se deben implementar son:

- Clase abstracta `flujo_entrada` con operaciones `int examina() const` (lee el siguiente carácter sin consumirlo) y `void consume()` (avanza el flujo).
- Clase `entrada_estandar` que implementa `flujo_entrada` sobre `std::cin`.
- Clase `entrada_cadena` que implementa `flujo_entrada` sobre un `std::string`.
- Función no miembro `operator>>(flujo_entrada&, int&)` que lee un entero saltando espacios en blanco, soporta signo `+` y `-`, y lanza `std::runtime_error` en caso de error.

#### Ejemplo de uso:

```cpp
int main() {
    entrada_estandar ent1;
    int a, b;
    ent1 >> a >> b;
    entrada_cadena ent2(" 123 456");
    int x, y;
    ent2 >> x >> y;
    std::cout << a << " " << b << "\n";
    std::cout << x << " " << y << "\n";
}
```

### Tarea 5:

Implementa un intérprete de un lenguaje simple de instrucciones usando polimorfismo. El programa lee instrucciones desde la entrada estándar y las ejecuta sobre una tabla de variables enteras.

Las instrucciones soportadas son:

- `ASIGNA <var> <valor>` — asigna un valor entero a una variable.
- `ASIGNA_CONDICIONAL <cond> <var> <valor>` — asigna el valor solo si la variable `cond` existe y es distinta de cero.
- `IMPRIME <var>` — imprime el valor de una variable; lanza error si no existe.

La arquitectura usa una clase base abstracta `instruccion` con método virtual puro `ejecuta(tabla_variables, salida)`, y una clase derivada por cada tipo de instrucción. La función `preprocesa` parsea el flujo de entrada y devuelve un vector de instrucciones; `ejecuta` las corre en orden.

#### Ejemplo de entrada:

```
ASIGNA x 5
ASIGNA cond 1
ASIGNA_CONDICIONAL cond y 10
IMPRIME x
IMPRIME y
```

#### Salida:

```
5
10
```

### Tarea 6:

Reimplementación en Java del tipo de dato `Conjunto` de la tarea 2, que modela un conjunto de enteros del 0 al 99.

Las operaciones implementadas son:

- Constructor por defecto que inicializa el conjunto vacío.
- `boolean inserta(int x)` — inserta un elemento; retorna `false` si ya existe o está fuera de rango.
- `boolean elimina(int x)` — elimina un elemento; retorna `false` si no existe o está fuera de rango.
- `int size()` — retorna el número de elementos en el conjunto.
- `int get(int v)` — retorna el v-ésimo elemento en orden ascendente; retorna `-1` si el índice está fuera de rango.
- `boolean equals(Conjunto c)` — compara dos conjuntos por igualdad.

#### Ejemplo de uso:

```java
var c = new Conjunto();
boolean b1 = c.inserta(3);
boolean b2 = c.inserta(1);
boolean b3 = c.inserta(3);
System.out.printf(" %b %b %b\n", b1, b2, b3);
System.out.printf(" %d\n", c.size());
for (int i = 0; i < c.size(); ++i) {
    System.out.printf(" %d ", c.get(i));
}
```

#### Salida:

```
 true true false
 2
 1  3
```
