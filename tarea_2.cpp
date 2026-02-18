#include <iostream>

class conjunto
{
 int values[100];
 int s;

public:
 conjunto()
 {
		s = 0;
		for (int i = 0; i < 100; i++)
		{
			this->values[i] = 0;
		}
 }

 explicit conjunto(int size, int val)
 {
 	this->s = size;
		for (int i = 0; i < size; i++)
			this->values[i] = val;
 }

 conjunto(const conjunto &oc)
 {
		this->s = oc.s;
		for (int i = 0; i < oc.s; i++)
		{
			this->values[i] = oc.values[i];
		}
 }

 conjunto &operator=(const conjunto &oc)
 {
		if (this == &oc)
			return *this;

		this->s = oc.s;
		for (int i = 0; i < oc.s; ++i)
		{
			this->values[i] = oc.values[i];
		}
		return *this;
 }

 bool inserta(int value)
 {
		if (value > 100 || value < 0 || s >= 100)
			return false;

		for (int i = 0; i < s; i++)
		{
			if (values[i] == value)
				return false;
		}

		int i = s - 1;
		while (i >= 0 && values[i] > value)
		{
			values[i + 1] = values[i];
			i--;
		}

		this->values[i + 1] = value;
		this->s++;
		return true;
 }

 bool elimina(int value)
 {
		int idx = -1;
		for (int i = 0; i < s; i++)
		{
			if (this->values[i] == value)
			{
				idx = i;
				break;
			}
		}

		if (idx == -1)
			return false;

		for (int i = idx; i < s - 1; i++)
		{
			this->values[i] = this->values[i + 1];
		}

		s--;
		return true;
 }

 int size() const
 {
		return this->s;
 }

 int operator[](int i) const
 {
		return this->values[i];
 }
};

bool operator==(const conjunto &a, const conjunto &b)
{
 if (a.size() != b.size())
		return false;
 for (int i = 0; i < a.size(); i++)
 {
		if (a[i] != b[i])
			return false;
 }
 return true;
}

bool operator!=(const conjunto a, const conjunto b)
{
 return !(a == b);
}

int main()
{
 conjunto c;
 bool b1 = c.inserta(3);
 bool b2 = c.inserta(1);
 bool b3 = c.inserta(3);

 std::cout << b1 << " "
		   << b2 << " "
		   << b3 << "\n";

 std::cout << c.size() << "\n";

 for (int i = 0; i < c.size(); ++i)
 {
		std::cout << c[i] << " ";
 }
 std::cout << "\n";
 conjunto d = c;
 std::cout << (c == d) << "\n";
}
