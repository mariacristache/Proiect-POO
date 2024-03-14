#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Stoc {
	string denumireIngredient;
	bool esteStoc;
public:
	Stoc() {
		denumireIngredient = "N/A";
		esteStoc = 0;
	}
	Stoc(string denumireIngredient, bool esteStoc) {
		this->denumireIngredient = denumireIngredient;
		this->esteStoc = esteStoc;
	}
	Stoc(Stoc& s) {
		this->denumireIngredient = s.denumireIngredient;
		this->esteStoc = s.esteStoc;
	}
	Stoc operator=(const Stoc& s) {
		if (this != &s) {
			this->denumireIngredient = s.denumireIngredient;
			this->esteStoc = s.esteStoc;
		}
		return *this;
	}
	string getDenumireIngredient() {
		return this->denumireIngredient;
	}
	void setDenumireIngredient(string denumireIngredient) {
		this->denumireIngredient = denumireIngredient;
	}

	bool getEsteStoc() {
		return this->esteStoc;
	}
	void setEsteStoc() {
		this->esteStoc = esteStoc;
	}

	~Stoc() {
	}
	friend ostream& operator<<(ostream& out, Stoc& s) {
		out << "\n----------------------------------------";
		out << "\nDenumirea ingredientului cu numarul este: " << s.denumireIngredient;
		out << "\nEste ingredientul in stoc? ";
		if (s.esteStoc == 1)
			out << "da, este in stoc!";
		else
			out << "nu este in stoc!";
		out << "\n----------------------------------------";
		return out;
	}
	friend istream& operator>>(istream& in, Stoc& s) {
		cout << "\n----------------------------------------";
		cout << "Introduceti denumirea ingredientului: ";
		in >> s.denumireIngredient;

		cout << "\nEste in stoc ingredientul " << s.denumireIngredient << "?";
		cout << "\n!tastati DA sau NU, cu majuscule!";
		string raspuns = "N/A";
		in >> raspuns;
		if (raspuns == "DA") {
			s.esteStoc = 1;
		}
		else
			if (raspuns == "NU") {
				s.esteStoc = 0;
			}
			else {
				cout << "\nRaspuns invalid, va rog tastati DA sau NU(cu majuscule)!!!!!!";
			}
		cout << "\n----------------------------------------";
		return in;
	}
	explicit operator bool() {
		return this->esteStoc;
	}
	friend bool operator==(bool stoc, const Stoc& s) {
		if (s.esteStoc != false) {
			return stoc == s.esteStoc;
		}
	}

};

class Ingredient {
	string denumireIngredient;
	int zileValabilitate;
	int nrAlergeni;
	string* alergeni;
	Stoc stoc;
public:
	Ingredient() {
		denumireIngredient = "N/A";
		zileValabilitate = 0;
		nrAlergeni = 0;
		alergeni = nullptr;
		stoc = Stoc();
	}

	Ingredient(string denumireIngredient, int zileValabilitate, int nrAlergeni, string* alergeni, Stoc stoc) {
		this->denumireIngredient = denumireIngredient;
		this->zileValabilitate = zileValabilitate;

		if (alergeni != nullptr && nrAlergeni > 0)
		{
			this->nrAlergeni = nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0;i < this->nrAlergeni;i++)
				this->alergeni[i] = alergeni[i];
			this->stoc = stoc;
		}
		
	}
	Ingredient(Ingredient& ing) {
		this->denumireIngredient = ing.denumireIngredient;
		this->zileValabilitate = ing.zileValabilitate;

		if (ing.alergeni != nullptr && ing.nrAlergeni > 0)
		{
			this->nrAlergeni = ing.nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0;i < this->nrAlergeni;i++)
				this->alergeni[i] = ing.alergeni[i];
		}
		this->stoc = ing.stoc;
	}

	Ingredient& operator=(Ingredient& ing) {
		if (this != &ing) {
			delete[] alergeni;
			alergeni = nullptr;
			//stoc.~Stoc();
			this->denumireIngredient = ing.denumireIngredient;
			this->zileValabilitate = ing.zileValabilitate;

			if (ing.alergeni != nullptr && ing.nrAlergeni > 0)
			{
				this->nrAlergeni = ing.nrAlergeni;
				this->alergeni = new string[this->nrAlergeni];
				for (int i = 0;i < this->nrAlergeni;i++)
					this->alergeni[i] = ing.alergeni[i];
			}
			else
			{
				this->nrAlergeni = 0;
				this->alergeni = nullptr;
			}

			this->stoc = ing.stoc;
		}
		return *this;
	}

	string getDenumireIngredient() {
		return this->denumireIngredient;
	}
	void setDenumireIngredient(string denumireIngredient) {
		this->denumireIngredient = denumireIngredient;
	}

	int getZileValabilitate() {
		return this->zileValabilitate;
	}
	void setZileValabilitate(int zileValabilitate) {
		this->zileValabilitate = zileValabilitate;
	}
	int getNrAlergeni() {
		return this->nrAlergeni;
	}
	void setNrAlergeni(int nrAlergeni) {
		this->nrAlergeni = nrAlergeni;
	}
	string* getAlergeni() {
		return this->alergeni;
	}
	void setAlergeni(string* alergeni, int nrAlergeniNou) {
		delete[]this->alergeni;
		this->alergeni = new string[nrAlergeniNou];
		for (int i = 0;i < nrAlergeniNou;i++) {
			this->alergeni[i] = alergeni[i];
		}
		this->nrAlergeni = nrAlergeniNou;
	}
	Stoc getStoc() {
		return this->stoc;
	}

	Stoc setStoc(Stoc stoc) {
		this->stoc = stoc;
	}

	~Ingredient() {
		delete[] alergeni;
		alergeni = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Ingredient& ing) {
		out << "\n----------------------------------------";
		out << "\nDenumirea ingredientului este: " << ing.denumireIngredient;
		out << "\nIngredientul este bun pentru " << ing.zileValabilitate << " zile!";
		out << "\nIngredientul contine " << ing.nrAlergeni << " alergeni";
		if (ing.alergeni != nullptr) {
			out << "\nLista alergenilor ce se regasesc in ingredient: ";
			for (int i = 0;i < ing.nrAlergeni;i++) {
				out << ing.alergeni[i] << ", ";
			}
		}
		out << "\n----------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Ingredient& ing) {
		delete[]ing.alergeni;
		cout << "\n----------------------------------------";
		cout << "\nIntroduceti denumirea ingredientului: ";
		in >> ing.denumireIngredient;
		cout << "\nIntroduceti numarul de zile pentru care ingredientul inca este bun: ";
		in >> ing.zileValabilitate;
		cout << "\nIntroduceti numarul de alergeni pe care il contine ingredientul: ";
		in >> ing.nrAlergeni;
		ing.alergeni = new string[ing.nrAlergeni];
		if (ing.nrAlergeni > 0) {
			cout << "\nIntroduceti lista de alergeni ai ingredientului: ";
			for (int i = 0;i < ing.nrAlergeni;i++) {
				in >> ing.alergeni[i];
			}
		}
		else
			cout << "\nIngredientul nu contine alergeni!";
		cout << "\n----------------------------------------";
		return in;

	}
	string operator[](int index) {
		if (index > 0 && index < this->nrAlergeni) {
			if (this->alergeni != nullptr)
				return this->alergeni[index];
		}
	}
	Ingredient& operator+(int zileValabilitateMinus) {
		if (zileValabilitateMinus > 0) {
			Ingredient ing = *this;
			ing.zileValabilitate -= zileValabilitateMinus;
			return ing;
		}
	}
	Ingredient& operator--() {
		this->zileValabilitate--;
		return *this;
	}
	Ingredient operator--(int) {
		Ingredient copie = *this;
		this->zileValabilitate--;
		return copie;
	}
	bool operator>=(const Ingredient& ing) {
		if (this->alergeni != nullptr && ing.alergeni != nullptr) {
			if (this->alergeni[this->nrAlergeni - 1] >= ing.alergeni[this->nrAlergeni - 1])
				return true;
			return false;
		}
	}
	friend bool operator==(string denumire, const Ingredient& ing) {
		if (ing.denumireIngredient != "N/A") {
			return denumire == ing.denumireIngredient;
		}
	}
	bool operator!() {
		return !this->stoc;
	}


};

class Preparat {

private:
	const int idPreparat;
	Ingredient* ingrediente;
	string denumirePreparat;
	int nrIngredientePreparat;
	int calorii;
	int pretPreparat;
public:
	Preparat() :idPreparat(idPreparat) {

	}
	Preparat(const int idPreparat) :idPreparat(idPreparat) {
		this->denumirePreparat = "N/A";
		this->nrIngredientePreparat = 0;
		this->calorii = 0;
		this->pretPreparat = 0;
		this->ingrediente = nullptr;
	}
	Preparat(const int idPreparat, string denumirePreparat,int nrIngredientePreparat, int calorii, int pretPreparat, Ingredient* ingrediente) :idPreparat(idPreparat) {
		this->denumirePreparat = denumirePreparat;
		this->nrIngredientePreparat = nrIngredientePreparat;
		this->calorii = calorii;
		this->pretPreparat = pretPreparat;
		if (ingrediente != nullptr && nrIngredientePreparat > 0) {
			this->ingrediente = new Ingredient[this->nrIngredientePreparat];
			for (int i = 0;i < this->nrIngredientePreparat;i++)
				this->ingrediente[i] = ingrediente[i];
		}
	}
	Preparat(Preparat& p) :idPreparat(p.idPreparat) {
		this->denumirePreparat = p.denumirePreparat;
		this->nrIngredientePreparat = p.nrIngredientePreparat;
		this->calorii = p.calorii;
		this->pretPreparat = p.pretPreparat;
		if (p.ingrediente != nullptr && p.nrIngredientePreparat > 0) {
			this->ingrediente = new Ingredient[this->nrIngredientePreparat];
			for (int i = 0;i < this->nrIngredientePreparat;i++)
				this->ingrediente[i] = p.ingrediente[i];
		}
	}

	Preparat& operator=(const Preparat& p){
		if (this != &p) {
			/*if (this->ingrediente != nullptr) {
				delete[]this->ingrediente;
			}*/
			this->ingrediente = nullptr;
			this->denumirePreparat = p.denumirePreparat;
			this->nrIngredientePreparat = p.nrIngredientePreparat;
			this->calorii = p.calorii;
			this->pretPreparat = p.pretPreparat;
			if (p.ingrediente != nullptr && p.nrIngredientePreparat > 0) {
				this->ingrediente = new Ingredient[this->nrIngredientePreparat];
				for (int i = 0;i < this->nrIngredientePreparat;i++)
					this->ingrediente[i] = p.ingrediente[i];
			}
		} return *this;

	}

	Ingredient* getIngrediente() {
		return this->ingrediente;
	}
	void setIngrediente(Ingredient* ingrediente,int nrIngredientePreparat) {
		delete[]this->ingrediente;
		if (ingrediente != nullptr && nrIngredientePreparat > 0) {
			this->ingrediente = new Ingredient[nrIngredientePreparat];
			for (int i = 0;i < nrIngredientePreparat;i++) {
				this->ingrediente[i] = ingrediente[i];
			}
		}
	}
	const int getIdPreparat() {
		return this->idPreparat;
	}

	string getDenumirePreparat() {
		return this->denumirePreparat;
	}
	void setDenumirePreparat(string denumirePreparat) {
		this->denumirePreparat = denumirePreparat;
	}

	int getNrIngredientePreparat() {
		return this->nrIngredientePreparat;
	}
	void setNrIngredientePreparat(int nrIngredientePreparat) {
		this->nrIngredientePreparat=nrIngredientePreparat;
	}
	int getCalorii() {
		return this->calorii;
	}
	void setCalorii(int calorii) {
		this->calorii = calorii;
	}
	int getPretPreparat() {
		return this->pretPreparat;
	}
	void setPretPreparat(int pretPreparat) {
		this->pretPreparat =pretPreparat;
	}

	~Preparat() {
		delete[]this->ingrediente;
		this->ingrediente = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Preparat& p) {
		out << "\n----------------------------------------";
		out << "\nId-ul preparatului este: " << p.idPreparat;
		out << "\nDenumirea preparatului este: " << p.denumirePreparat;
		out << "\n Numarul de ingrediente pe care il contine preparatul este: " << p.nrIngredientePreparat;
		out << "\n Numarul de calorii ce se afla in preparat: " << p.calorii;
		out << "\n Pretul preparatului este: " << p.pretPreparat;
		out << "\n Ingredientele din preparat: ";
		for (int i = 0;i < p.nrIngredientePreparat;i++)
		{
			out << "\n" << p.ingrediente[i];
		}
		out << "\n----------------------------------------";
		return out;
	}
	friend istream& operator>>(istream& in, Preparat& p) {
		cout << "\n----------------------------------------";
		cout << "\nIntroduceti denumirea preparatului: ";
		in >> p.denumirePreparat;
		cout << "\nIntroduceti numarul de ingrediente ce se regasesc in preparat: ";
		in >> p.nrIngredientePreparat;
		cout << "\nIntroduceti numarul de calorii ce se afla in preparat: ";
		in >> p.calorii;
		cout << "\nIntroduceti pretul preparatului: ";
		in >> p.pretPreparat;

		cout << "\n----------------------------------------";
		return in;
	}

	/*string operator[](int index) {
		if (index > 0 && index < this->nrIngredientePreparat) {
			if (this->ingrediente!= nullptr)
				return this->ingrediente[index];
		}*/

	Preparat& operator+(int caloriiSuplimentare) {
		if (caloriiSuplimentare > 0) {
			Preparat p = *this;
			p.calorii += caloriiSuplimentare;
			return p;
		}
	}
	Preparat& operator++() {
		this->calorii++;
		return *this;
	}
	Preparat operator++(int) {
		Preparat copie = *this;
		this->calorii++;
		return copie;
	}
	bool operator>=(const Preparat& p) {
		if (this->ingrediente != nullptr && p.ingrediente != nullptr) {
			if (this->ingrediente[this->nrIngredientePreparat - 1] >= p.ingrediente[this->nrIngredientePreparat - 1])
				return true;
			return false;
		}
	}
	friend bool operator==(string denumire, const Preparat& p) {
		if (p.denumirePreparat != "N/A") {
			return denumire == p.denumirePreparat;
		}
	}
	explicit operator float() {
		return this->calorii;
	}
	//void modificaPretMinim(int pretMinimNou) {
	//	if (pretMinimNou > 0 && pretMinimNou != this->pretPreparat) {
	//		if (this->pretPreparat < pretMinimNou) {
	//			this->pretPreparat = pretMinimNou;
	//		}
	//	}
	//}

	bool poateFiPreparat() {
		for (int i = 0;i < this->nrIngredientePreparat;i++) {
			if (ingrediente[i].getStoc().getEsteStoc() == false) return false;
		}
		return true;
	}

};

class Comanda {
	int nrElementeComanda;
	Preparat* preparat;
	int* nrBucatiPreparat;
	static float procentTips;
public:
	Comanda() {
		nrElementeComanda = 0;
		preparat = nullptr;
		nrBucatiPreparat = nullptr;
	}
	Comanda(int nrElementeComanda,int*nrBucatiPreparat,Preparat* preparat) {
		if(nrElementeComanda>0)
			this->nrElementeComanda = nrElementeComanda;
		if (nrBucatiPreparat != nullptr&&nrElementeComanda>0) {
			this->nrBucatiPreparat = new int[this->nrElementeComanda];
			for (int i = 0;i < this->nrElementeComanda;i++)
				this->nrBucatiPreparat[i] = nrBucatiPreparat[i];
		}
		if (preparat != nullptr && nrElementeComanda > 0) {
			this->preparat = new Preparat[this->nrElementeComanda];
			for (int i = 0;i < this->nrElementeComanda;i++)
				this->preparat[i] = preparat[i];
		}
	}
	Comanda(const Comanda& c) {
		if (c.nrElementeComanda > 0)
			this->nrElementeComanda = c.nrElementeComanda;
		if (c.nrBucatiPreparat != nullptr && c.nrElementeComanda > 0) {
			this->nrBucatiPreparat = new int[this->nrElementeComanda];
			for (int i = 0;i < this->nrElementeComanda;i++)
				this->nrBucatiPreparat[i] = c.nrBucatiPreparat[i];
		}
		if (c.preparat != nullptr && c.nrElementeComanda > 0) {
			this->preparat = new Preparat[this->nrElementeComanda];
			for (int i = 0;i < this->nrElementeComanda;i++)
				this->preparat[i] = c.preparat[i];
		}
	}

	Comanda& operator=(Comanda& c) {
		if (this != &c) {
			delete[]nrBucatiPreparat;
			nrBucatiPreparat = nullptr;
			delete[]preparat;
			preparat = nullptr;
			if (c.nrElementeComanda > 0)
				this->nrElementeComanda = c.nrElementeComanda;
			if (c.nrBucatiPreparat != nullptr && c.nrElementeComanda > 0) {
				this->nrBucatiPreparat = new int[this->nrElementeComanda];
				for (int i = 0;i < this->nrElementeComanda;i++)
					this->nrBucatiPreparat[i] = c.nrBucatiPreparat[i];
			}
			if (c.preparat != nullptr && c.nrElementeComanda > 0) {
				this->preparat = new Preparat[this->nrElementeComanda];
				for (int i = 0;i < this->nrElementeComanda;i++)
					this->preparat[i] = c.preparat[i];
			}
		}
		return *this;
	}

	int getNrElementeComanda() {
		return this->nrElementeComanda;
	}
	void setNrElementeComanda(int nrElementeComanda) {
		this->nrElementeComanda = nrElementeComanda;
	}
	Preparat* getPreparat() {
		return this->preparat;
	}
	void setPreparat(Preparat* preparat, int nrElementeComanda) {
		delete[]this->preparat;
		if (preparat != nullptr && nrElementeComanda > 0) {
			this->preparat = new Preparat[nrElementeComanda];
			for (int i = 0;i < nrElementeComanda;i++) {
				this->preparat[i] = preparat[i];
			}
		}
	}
	int* getNrBucatiPreparat() {
		return this->nrBucatiPreparat;
	}
	void setNrBucatiPreparat(int* nrBucatiPreparat, int nrElementeComanda) {
		delete[]this->nrBucatiPreparat;
		this->nrBucatiPreparat = new int[nrElementeComanda];
		for (int i = 0;i < nrElementeComanda;i++) {
			this->nrBucatiPreparat[i] = nrBucatiPreparat[i];
		}
		this->nrElementeComanda = nrElementeComanda;
	}

	static float getProcentTips() {
		return procentTips;
	}
	static void setProcentTips(float procentTips) {
		Comanda::procentTips = procentTips;
	}

	~Comanda() {
		delete[]nrBucatiPreparat;
		nrBucatiPreparat = nullptr;
		delete[]preparat;
		preparat = nullptr;
	}
	friend ostream& operator<<(ostream& out, Comanda& c) {
		out << "\n----------------------------------------";
		out << "\nAti comandat " << c.nrElementeComanda << " preparate diferite";
		out << "\nNumarul total de preparate comandate: ";
		int suma = 0;
		for (int i = 0;i < c.nrElementeComanda;i++) {
			suma += c.nrBucatiPreparat[i];
		}
		out << suma;
		out << "\n Preparatele comandate sunt: ";
		for (int i = 0;i < c.nrElementeComanda;i++) {
			out << "\n" << c.preparat[i];
		}
		out << "\nProcentul recomandat de tips este: " << c.procentTips << "%";
		out << "\n----------------------------------------";
		return out;
	}
	friend istream& operator>>(istream& in, Comanda& c) {
		cout << "\n----------------------------------------";
		delete[]c.nrBucatiPreparat;
		delete[]c.preparat;
		cout << "\nCate preparate diferite vreti sa comandati? ";
		in>>c.nrElementeComanda;
		c.nrBucatiPreparat = new int[c.nrElementeComanda];
		cout << "\n Ce cantitate doriti sa comandati din fiecare preparat: ";
		for (int i = 0;i < c.nrElementeComanda;i++) {
			in>> c.nrBucatiPreparat[i];
		}
		cout << "\n----------------------------------------";
		return in;
	}


};
float Comanda::procentTips = 10;

class Meniu {
	static int nrPreparate;
	Preparat* preparat;
public:
	Meniu() {
		preparat = nullptr;
	}
	Meniu(Preparat* preparat) {
		if (preparat != nullptr && this->nrPreparate > 0) {
			this->preparat = new Preparat[this->nrPreparate];
			for (int i = 0;i < this->nrPreparate;i++)
				this->preparat[i] = preparat[i];
		}

	}
	Meniu(Meniu& m) {
		if (m.preparat != nullptr && this->nrPreparate > 0) {
			this->preparat = new Preparat[this->nrPreparate];
			for (int i = 0;i < this->nrPreparate;i++)
				this->preparat[i] = m.preparat[i];
		}
	}
	Meniu& operator=(Meniu& m) {
		if (this != &m) {
			delete[]preparat;
			preparat = nullptr;
			if (m.preparat != nullptr && this->nrPreparate > 0) {
				this->preparat = new Preparat[this->nrPreparate];
				for (int i = 0;i < this->nrPreparate;i++)
					this->preparat[i] = m.preparat[i];
			}
		}
		return *this;
	}

	static int getNrPreparate() {
		return nrPreparate;
	}
	static void setNrPreparate(int nrPreparate) {
		Meniu::nrPreparate = nrPreparate;
	}
	Preparat* getPreparat() {
		return this->preparat;
	}
	void setPreparat(Preparat* preparate, int nrPreparate) {
		delete[]this->preparat;
		if (preparat != nullptr && nrPreparate > 0) {
			this->preparat = new Preparat[nrPreparate];
			for (int i = 0;i < nrPreparate;i++) {
				this->preparat[i] = preparat[i];
			}
		}
	}
	~Meniu() {
		delete[]preparat;
		preparat = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "\n----------------------------------------";
		out << "\n Meniul contine " << m.nrPreparate << " preparate";
		out << "\n Preparatele din meniu sunt: ";
		for (int i = 0;i < m.nrPreparate;i++) {
			out << m.preparat[i] << ", ";
		}
		out << "\n----------------------------------------";
		return out;
	}
	//friend istream& operator>>(istream& in, Meniu& m) {
	//	return in;
	//}

};
int Meniu::nrPreparate = 4;

int main() {
	Stoc s("chifle", true);
	Stoc s1("carne", true);
	Stoc s2("paste", true);
	Stoc s3("sos", true);
	Stoc s4("rosii", true);
	Stoc s5("sare", true);
	Stoc s6("aluat", true);
	Stoc s7("branza", true);
	Stoc s8("sunca", true);
	Stoc stoc[] = {s,s1,s2,s3,s4,s5,s6,s7,s8};

	string alg[] = { "oua", "lapte","faina"};
	string alg2[] = {"carne"};
	string alg3[] = {"rosii"};
	string alg4[] = {"sare"};
	string alg5[] = {"lapte"};

	Ingredient i1("chifle", 3, 3, alg, s);
	Ingredient i2("carne", 4, 1, alg2, s1);
	Ingredient i3("paste", 30,3,alg,s2);
	Ingredient i4("sos", 25,1,alg3,s3);
	Ingredient i5("rosii", 4,1,alg3,s4);
	Ingredient i6("sare", 30,1,alg4,s5);
	Ingredient i7("aluat", 2,3,alg,s6);
	Ingredient i8("branza", 10,1,alg5,s7);
	Ingredient i9("sunca", 10,1,alg2,s8);


	Ingredient ingrediente1[] = { i1,i2,i5,i8 };
	Ingredient ingrediente2[] = { i5,i6,i8 };
	Ingredient ingrediente3[] = { i2,i3,i4,i8 };
	Ingredient ingrediente4[] = { i4,i7,i8,i9 };

	Preparat p1(1, "burger", 2, 350, 25, ingrediente1);
	Preparat p2(2,"supa",3,200,10,ingrediente2);
	Preparat p3(3, "paste", 4, 260, 30, ingrediente3);
	Preparat p4(4,"pizza",4,400,35,ingrediente4);

	Preparat preparate[] = {p1,p2,p3,p4};
	Meniu m(preparate);
	int nrBucati[] = { 2,0,3,4 };
	Comanda c(4,nrBucati,preparate);

	int alegere;
	do {
		cout << "\n-------------------------------------";
		cout << "\n1.Afiseaza meniul";
		cout << "\n2.Comandati";
		cout << "\n3.Afiseaza comanda";
		cout << "\n4.Afiseaza pretul total al comenzii";
		cout << "\n5.Ce ingrediente sunt in stoc";
		cout << "\n0.Iesire";
		cout << "\n-------------------------------------";
		cout << "\nIntroduceti alegerea dumneavoastra: ";
		cin >> alegere;

		switch (alegere) {
		case 1: {
			for (int i = 0;i < Meniu::getNrPreparate(); i++) {
				if (preparate[i].poateFiPreparat()==true)
					cout << preparate[i]<<endl;
			}
			break;
			}

		case 2: {
			int* numar=new int[Meniu::getNrPreparate()];
			for (int i = 0;i < Meniu::getNrPreparate();i++) {
				cout << "\nCate bucati din preparatul "<<preparate[i].getDenumirePreparat()<<" doriti? ";
				cin >> numar[i];
			}
			c.setNrBucatiPreparat(numar, Meniu::getNrPreparate());
			//cout << c;
			delete[]numar;
			break;
			}

		case 3: {
			cout << c;
			break;
			}
		case 4: {
			float total = 0;
			for (int i = 0;i < c.getNrElementeComanda(); i++) {
				if (c.getNrBucatiPreparat()[i] != 0)
					total += c.getNrBucatiPreparat()[i] * preparate[i].getPretPreparat();
			}
			cout <<"\nTotalul de achitat al comenzii este: "<<total;
			cout <<"\nTotalul de achitat al comenzii + tips este: "<<total+total/c.getProcentTips();
			break;
		}
		case 5: {
			int numar = sizeof(stoc) / sizeof(stoc[0]);
			for (int i = 0;i < numar; i++) {
				if (s.getEsteStoc() == true)
					cout << stoc[i]<<", ";
			}
			break;
			}
		case 0: {
			cout << "\nLa revedere!";
			break;
		}
		default: cout << "Optiune invalida, reintroduceti o optiune valida"; break;
		}

	}while (alegere != 0);

	

	

	return 0;
}