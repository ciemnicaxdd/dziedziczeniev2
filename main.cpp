#include <iostream>
#include <fstream>

using namespace std;

class dziedziczenie

{
	public:

	ifstream plik1;
	ofstream plik2;


};

class film :

public dziedziczenie
{
	public:
    string tytul, rezyser;
	int rok;

		void z();
		void save();
};

void film::save()
{
	plik2<<"{\"tytul\":\""<<tytul<<"\", \"rezyser\":\""<<rezyser<<"\", \"rok\":\""<<rok<<"\"}\n";
}

void film::z()
{
	plik1.open("plik1.txt");
	plik2.open("plik2.txt");


	plik2<<"["<<endl;

	while(!plik1.eof())

{
    plik1>>tytul>>rezyser>>rok;
    save();
}
	plik2<<"]";


	plik1.close();
	plik2.close();
}


class dokument : public film
{
	string description;
	public:
		void z();
		void save();
};

void dokument::save()

{
	plik2<<"{\"tytul\":\""<<tytul<<"\", \"rezyser\":\""<<rezyser<<"\", \"rok\":\""<<rok<<"\", \"opis\":\""<<description<<"\"},\n";
}

void dokument::z()
{
	plik1.open("plik1.txt");
	plik2.open("plik2.txt");


	plik2<<"["<<endl;

	while(!plik1.eof())

{
    plik1>>tytul>>rezyser>>rok>>description;

    save();
}
	plik2<<"]";


	plik1.close();
	plik2.close();
}




int main(int argc, char** argv)
{
	dokument t1;
	t1.z();
	return 0;
}
