# Códigos clase de POO UAM-A

## Ing. en computación

---

La intención de este repositorio es almacenar las tareas y trabajos realizados en la materia de POO de la UAM-A.

## Tareas

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
