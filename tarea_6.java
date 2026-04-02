
class Conjunto{
 boolean[] elementos = new boolean[100];

 Conjunto(){
  for(int i = 0; i < 100; i++){
   elementos[i] = false;
  }
 }

 static int minimo(){
  return 0;
 }

 static int maximo(){
  return 0;
 }

 boolean inserta(int x) {
  if(x < 0 || x >= 100){
   return false;
  }
  if(elementos[x]){
   return false;
  } else {
   elementos[x] = true;
   return true;
  }
 }

 boolean elimina(int x) {
  if(x < 0 || x >= 100){
   return false;
  }
  if(elementos[x]){
   elementos[x] = false;
   return true;
  } else {
   return false;
  }
 }

 int size(){
  int count = 0;
  for(int i = 0; i < 100; i++){
   if(elementos[i]){
    count++;
   }
  }
  return count;
 }

 int get(int v){
  if(v < 0 || v >= size()){
   return -1;
  }
  int count = 0;
  for(int i = 0; i < 100; i++){
   if(elementos[i]){
    if(count == v) return i;
    count++;
   }
  }
  return -1;
 }

 boolean equals(Conjunto c){
  for(int i = 0; i < 100; i++){
   if(this.elementos[i] != c.elementos[i]){
    return false;
   }
  }
  return true;
 }

}

class Main{
 public static void main(String[] args){
  var c = new Conjunto( );
  boolean b1 = c.inserta(3);
  boolean b2 = c.inserta(1);
  boolean b3 = c.inserta(3);
  System.out.printf(" %b %b %b\n",
  b1, b2, b3);
  System.out.printf(" %d\n", c.size( ));
  for (int i = 0; i < c.size( ); ++i) {
  System.out.printf(" %d ", c.get(i));
  }
  System.out.println( );
  var d = new Conjunto( );
  d.inserta(1);
  d.inserta(3);
  System.out.print(c.equals(d));
 }
}