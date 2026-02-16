#include <iostream>

class conjunto {
	int values[100];
	int s;
	
	
	public:
		conjunto() {
      		s = 0;
			for(int i = 0; i < 100; i++){
				this->values[i] = 0;
			}	
   		}	
   		
   		conjunto(const conjunto& v) {
      		this->s = v.s;
      		for (int i = 0; i < v.s; ++i) {
         		this->values[i] = v.values[i];
      		}		
   		}
   		
   		conjunto(std::initializer_list<int> c){
		  	this->s = 0;
		    for (int v : c) {
		    	inserta(v);
		    }
		}

   		void operator=(const conjunto& v) {
      		this->s = v.s;
      		for (int i = 0; i < v.s; ++i) {
         		this->values[i] = v.values[i];
      		}
   		}
		
		bool inserta(int value){
			if( this->values[value-1] == value && value != 0){
				return false;
			}
			this->values[value-1] == value;
			this->s++;
			return true;
		}
		
		bool elimina (int value){
			if( this->values[value-1] == 0 && value != 0){
				return false;
			}
			this->values[value-1] == 0;
			this->s--;
			return true;
		}
		
		int size(){
			return this->s;
		}
		
		int operator[](int i){
			return this->values[i];
		}
		
};


bool operator==(const conjunto a, const conjunto b){
	if (a.size() != b.size()) return false;
	
	for(int i = 0; i<a.size(); i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

bool operator!=(const conjunto a, const conjunto b){
	if (a.size() != b.size()) return true;
	
	for(int i = 0; i<a.size(); i++){
		if(a[i] != b[i]) return true;
	}
	return false;
}

int main (){
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
