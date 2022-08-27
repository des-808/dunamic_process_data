#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;



class Element
{
	int Data;
	Element* pNext;
	static int count;
public:

	int get_Data()const {
		return this->Data;
	}
	void set_Data(int Data) {
		 this->Data = Data;
	}
	Element* get_pNext()const {
		return pNext;
	}
	void set_pNext(Element* pNext) {
		this->pNext = pNext;
	}


	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		//cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		//cout << "EDestructor:\t" << this << endl;
	}

	friend class ForwardList;
};
int Element::count = 0;

class ForwardList {
	Element* Head;
	unsigned int size;
public:
	
	Element* get_Head()const {
		return Head;
	}
	void set_Head(Element* Head) {
		this->Head = Head;
	}

	ForwardList() {
		Head = nullptr;
		//cout << "LConstructor: " << this << endl;
	}
	
	ForwardList(const std::initializer_list<int>&il):ForwardList() {

		//cout << typeid(il.begin()).name() << endl;


		for (int const* it = il.begin(); it != il.end(); it++) {
			push_back(*it);
		}
	}

	~ForwardList() {
		while (Head)pop_front();
		///cout << "LDestructor: " << this << endl;
	}
	////////////////////////////////////////////////////////////////////
	
	ForwardList& operator=(const ForwardList& other)
	{
		//1) Удаляем старое значение объекта:
		while (Head)pop_front();
		//2) Выполняем побитовое копирование:
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	////////////////////////////////////////////////////////////////////

	void push_front(int Data) {
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/

		Head = new Element(Data,Head);
		size++;
	}

	void push_back(int Data)
	{
		if (get_Head() == nullptr)return push_front(Data);
		//Element* New = new Element(Data);
		Element* Temp = Head;
		//for (Element* Temp = Head; Temp->pNext != nullptr; Temp = Temp->pNext)Temp->pNext = New;
		while (Temp->pNext != nullptr) {
			Temp = Temp->pNext;// переход на следующий элемент
		}
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
		size++;
	}

		void print()const {

			//Element* Temp = Head;
			//while (Temp) {
			//	cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			//	Temp = Temp->pNext;// переход на следующий элемент
			//}
			for (Element* Temp = Head; Temp;Temp=Temp->pNext){ 
				cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl; 
			}
			cout << "колличество элементов списка :" << size << endl;
			cout <<" общее колличество элементов : " << Element::count << endl;
		}


		void pop_front() {//удалить элемент с начала списка
			Element* Erased = Head;
			Element* Temp = Head;
			Temp = Temp->pNext;
			Head = Temp;
			delete Erased;
			size--;
		}

		void pop_back() {//удалить элемент с конца списка
			Element* Temp = Head;
			while (Temp->pNext->pNext) {
				Temp = Temp->pNext;
			}
			delete Temp->pNext;
			Temp->pNext = nullptr;
			size--;
		}

		void insert(int Data, int Index) {
			//Element* New = new Element(Data);
			Element* Temp = Head;
			for (int i = 0; i < Index - 1; i++) { Temp = Temp->pNext; }
			//New->pNext = Temp->pNext;
			//Temp->pNext = New;
			Temp->pNext = new Element(Data,Temp->pNext);
			size++;
		}
};

ForwardList& operator+(const ForwardList& left, const ForwardList& right) {
	ForwardList result; 
	Element* TempLeft = left.get_Head();
	Element* TempRight = right.get_Head();
	Element* Temp = right.get_pNext();

	result.set_Head(TempLeft);
	//for(TempLeft.get_pNext();)
	//result.set_pNext()
	//while (TempLeft != nullptr) { cout << "nullptr " << endl; }
	//result.
	//while()
	
	////result 
	//if (left.get_Head() == nullptr)return left.push_front(left.get_Data());
	////Element* New = new Element(Data);
	//
	////for (Element* Temp = Head; Temp->pNext != nullptr; Temp = Temp->pNext)Temp->pNext = New;
	//while (Temp->get_pNext() != nullptr) {Temp = Temp->get_pNext();// переход на следующий элемент
	//}
	////Temp->pNext = New;
	//Temp->get_pNext() = new Element(Data);



	return result;
}


//#define BASE_CHECK
//#define RANGE_BASED_FOR_ARRAY
	int main() {
		setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
		int n;
		cout << "введите размер списка  "; cin >> n;
		ForwardList list;
		//ForwardList list2;
		for (int i = 0; i < n; i++) {
			list.push_front(rand() % 100);
		}
		list.print();
		/*for (int i = 0; i < n; i++) {
			list.push_back(rand() % 100);
		}*/
		/*list.push_back(123);
		list.print();
		list.pop_front();
		list.print();
		list.pop_back();
		list.print();*/
		list.insert(12, 3);
		list.print();
		/*	for (int i = 0; i < n; i++) {
				list2.push_front(rand() % 100);
			}
			for (int i = 0; i < n; i++) {
				list.push_back(rand() % 100);
			}
			list2.push_back(123);
			list2.print();
			list2.pop_front();
			list2.print();
			list2.pop_back();
			list2.print();
			list2.insert(12, 3);
			list2.print();*/
#endif // BASE_CHECK
#ifdef RANGE_BASED_FOR_ARRAY
		int arr[] = { 3,5,8,13,21 };
		//for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {cout << arr[i] << "\t";}

		for (int i : arr) { cout << i << "\t"; }
#endif // RANGE_BASED_FOR_ARRAY


		ForwardList list = { 3,5,8,13,21 };
		ForwardList list2 = { 2,5,9,13 };
		ForwardList list4 = { 13,75,19,43 };
		ForwardList list3 = list2 + list4;
	
		
		//list.print();
		list3.print();



		return 1;
	}

























/*

простейшая структыра данных это массив
массив это наюор элементов одного типа в непрерывной области памяти.
непрепывная обл памяти одновр явл как приимуществом так и недостатком массива
глывным приимуществом массива явл быстрый доступ к элементам который осущ за конст время поскольку сводится к операции сложения
а операция сложения выполн процессором законстантное время
скорость доступа к любому элем массива не зависит от размера массива.

главным недостатком массива явл сложность добавления и удаления элементов 
которая приводит к доп затратам опер пам и процессорного времени
поскольку требует полного переопред пам занимаемой массивом
обьем затрачиваемых ресурсов так же зависит от размера массива
чем больше массив тем больше памяти нужно выделить для его переопределения массива и так же тем дольше будут данные копир из исходного массива в новый

все недостатки массивов устраняют списки
Список это набор элем       каждый из которых содержит адресс следующего элем
и если массив даёт произвольный доступ к элем список даёт последовательный доступ к элементам. последний элем списка
всегда указывает на 0
нооооо благодоря произвольным областям памяти список может создать элемент где есть свободное место и прикрепить 
его к остальному списку. это я вл осн приемущ спика
 добавл удал элем за конст время. но произвольн областя пам так же явл недостатком списка. это медленный доступ 
 к элем списка зависящий от размера списка. 
 и чем длиннне список тем дольше нужно проходить его элементы

 список реализуется при помощи 2х классов
 класс Element описывает структуру элемента. каждый элем списка содержит зная и адр следующего элемента.
 класс список    отвечает за добавление удаление элементов и тд

 Temp это итератор. 
 Итератор это указатель при помощи которого можно получить доступ к элем структур данных

 Статические члены класса


 статической назыв переменная принадл не кк какому то обьекту а к всему классу
 к статич переменной имеют равноправный доступ все обьекты данного класса

 при помощи статических переменных очень удобно считать колличество обьектов класса

 initializer_list  это контейнер
 контейнер это обьект который организует хранение других обьектов в память
 у любого контейнера есть методы begin() возвращает итератор на начало контейнера и
 end()  возвращает итератор на конец контейнера

 
*/