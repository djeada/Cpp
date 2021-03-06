# C-and-Cpp
Kod źródłowy do programów z yt.


Spis Treści
=================

<!--ts-->
   * [Proces kompilacji](#Proces-kompilacji)
   * [Preprocesor](#Preprocesor)
   * [Zmienne](#Zmienne)
   * [Interakcja z konsolą](#Interakcja-z-konsolą)
   * [Instrukcje sterujące](#Instrukcje-sterujące)
   * [Pętle](#Pętle)
   * [Liczby losowe](#Liczby-losowe)
   * [Funkcje](#Funkcje)
   * [Wskaźniki](#Wskaźniki)
   * [Tablice](#Tablice)
   * [Napisy](#Napisy)
   * [Pola bitowe](#Pola-bitowe)
   * [Operacje bitowe](#Operacje-bitowe)
   * [Iteratory](#Iteratory)

<!--te-->

<h1>Proces kompilacji</h1>
<ol>
<li> Najpierw na scenę wkracza Pan Preprocesor. Zadań tego Pana jest wiele, wśród nich wymienić można:
<dl>
<dd>- Włączenie zawartości załączonych plików nagłówkowych do kodu źródłowego. Na przykład jeśli w jednym z kompilowanych plików umieśiliśmy <i>#include "plik.h"</i> to treść tego pliku zostanie przekopiowana do naszego kodu źródłowego. </dd> 
<dd>- Generacja kodu makr. </dd>
<dd>- Zamiana stałych zdefiniwanyh za pomocą <i>#define</i> na ich wartości. </dd>
</dl>
</li>
<li> Kod źródłowy przygotowany przez Pana Preprocesora jest następnie poddany analizie składni, w której skład wchodzą:
	<dl>
		<dd> - Analiza leksykalna (np. odrzucenie zakomentowanych fragmentów kodu). </dd>
		<dd> - Analiza składni (np. czy nie próbujemy skorzystać ze zmiennej zanim została stworzona). </dd>
		<dd> - Analiza semantyczna (np. weryfikacja typów i poprawność instrukcji). </dd>
	</dl>
<li> Z kodu assemblera tworzone są pliki obiektowe, z rozszerzeniem </i>.o</i>. </li>
<li> Przygotowany w ten sposób kod obiektowy jest łączony z kodem obiektowym funkcji z zewnętrznych bibliotek w wykonywalny program (na Windowsie będzie mieć rozszerzenie .exe). </li>
</ol>

<h1>Preprocesor</h1>
Pan Preprocesor przetwarza kod źródłowy.

Zadania Pana Preprocesora definiowane są za pomocą specjalnych zaklęć zwanych dyrektywami rozpoczynanych od kratki <i>#</i>. 
Dyrektywy mogą być umieszczane są w dowolnym miesjscu programu, ale przyjęło się że najczęściej gromadzi się je u góry pliku źródłowego.

Najczęściej spotykaną dyrektywą będzie załączenie biblioteki.

```c++
#include <something>
```

Za pomocą dyrektyw możemy definiować stałe.

```c++
#define TRUE 1
```

Możemy również włączyć/wyłączyć część kodu w zależności od danego warunku. Działa to tak samo jak zwykłe instrukcje warunkowe z tym, że podane warunki ustalane są przed uruchomieniem programu.

```c++
#if 1 == 1
// kod
#else
// inny kod
#endif
```

<h1>Zmienne</h1>
<h4>Stworzenie zmiennej:</h4>
<p><em>Typ + nazwa;</em></p>

```c++
int x;
double y;
```

<h4> Zasady nazewnictwa zmiennych </h4>

Nazwy zmiennych mogą składać się z: </br>
a) liter </br>
b) liczb </br>
c) podkreślnika "_" </br>

Muszą zaczynać się od litery bądź podkreślnika. </br>

Nazwa zmiennej powinna coś znaczyć np. <i>liczbaSamochodow</i>, bądź <i>kolorTla</i>.

Są różne konwencje tworzenie złożonych nazw zmiennych. Dwie najpopularniejsze współcześnie to:

a) oddzielanie słów podkreślnikiem np. masa_czastki_alfa.
b) oddzielanie słów wielką literą np. masaCzastkiAlfa.

<h4>Inicjalizacja</h4>

```c++
x = 10;
y = 3.56;
```
<h4>Nadpisanie:</h4>

```c++
x = 10;
x = x + 3;
x++;
```

<h4>Typy zmiennych</h4>
<table class="boxed">
<tbody>
<tr>
<th>Grupa</th>
<th>Deklaracja w kodzie</th>
<th>Precyzja oraz rozmiar</th>
</tr>
<tr>
<td rowspan="4">Pojedyncze znaki</td>
<td>char</td>
<td>Jeden bajt. Najczęściej 8 bitów.</td>
</tr>
<tr>
<td>char16_t</td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>char32_t</td>
<td>Nie mniejszy niż  <code>char16_t</code>.Co najmniej 32 bity.</td>
</tr>
<tr>
<td>wchar_t</td>
<td>Najwięcej znaków pod jedną nazwą.</td>
</tr>
<tr>
<td rowspan="5">Liczby całkowite</td>
<td>signed char</td>
<td>Taki sam rozmiar jak <code>char</code>. Co najmniej 8 bitów.</td>
</tr>
<tr>
<td>signed short int</code></td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>signed int </td>
<td>Nie mniejszy niż  <code>short</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>signed long int</code></td>
<td>Nie mniejszy niż  <code>int</code>. Co najmniej 32 bitów.</td>
</tr>
<tr>
<td>signed long long int</code></td>
<td>Nie mniejszy niż <code>long</code>. Co najmniej 64 bitów.</td>
</tr>
<tr>
<td rowspan="5">Liczby naturalne</td>
<td>unsigned char</td>
<td rowspan="5">Tak jak całkowite.</td>
</tr>
<tr>
<td>unsigned short <em>int</em></code></td>
</tr>
<tr>
<td>unsigned <em>int</em></code></td>
</tr>
<tr>
<td>unsigned long <em>int</em></code></td>
</tr>
<tr>
<td>unsigned long long <em>int</em></code></td>
</tr>
<tr>
<td rowspan="3">Liczby zmiennoprzecinkowe</td>
<td>float</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>double</td>
<td>Precyzja nie mniejsza niż dla<code>float</code>.</td>
</tr>
<tr>
<td>long double</td>
<td>Precyzja nie mniejsza niż dla <code>double</code>.</td>
</tr>
<tr>
<td>Typ logiczny</td>
<td>bool</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Typ void</td>
<td>void</td>
<td>nic nie przechowuje</td>
</tr>
</tbody>
</table>
<p>&nbsp;&nbsp;</p>

<h4>Stałe</h4>
Zmiana przechowywanej wartości jest zablokowana.

```c++
const double pi = 3.14; 
  
// Tak nie robimy!
const double doInicjalizacji;
  
// Tak nie robimy!
bool prawda true;
const bool zawsze_prawda = prawda;
```
<h4>Zakres życia zmiennych</h4>

```c++
int liczba = 5;

if(liczba % 2 == 1){
	int liczba = 3; // zmienna lokalna!

	cout << liczba << endl;	// 3
}

cout << liczba << endl;	// 5
```

```c++
int a = 10; // zmienna globalna

int main(){
	int a = 3; // zmienna lokalna

	cout << a << endl;	// 3
  cout << ::a << endl;	// 10
}
```

<h1>Interakcja z konsolą</h1>
<p>&nbsp;Biblioteka <em>&lt;iostream&gt;&nbsp;</em>zawiera definicje:</p>
<ul>
<li>obiekt&nbsp;<em><strong>cout</strong>&nbsp;</em>oraz operator <strong>&lt;&lt;&nbsp;</strong>wypisuje tekst na konsole;</li>
<li>obiekt&nbsp;<em><strong>cin</strong>&nbsp;</em>oraz operator&nbsp;<strong>&gt;&gt; </strong>wczytują&nbsp;pojedynczą wartość;</li>
<li><em>getline(cin, string);&nbsp;</em>wczytuje cały wiersz wraz ze sacjami;</li>
</ul>

```c++
#include <iostream>

using namespace std;

int main(){
    int liczba;
    cout << "Podaj pojedynczą liczbę: "<< endl;
    cin >> liczba;        
    
    cout << "Podałeś liczbę: " << liczba << endl; 
    
    cin.ignore();  //wyczyszczenie bufora
    
    string zadanie;
    cout << "Podaj pełne zdanie: "<< endl;

    getline(cin, zdanie);
    
    cout << "Podałeś zdanie: " << endl << zdanie << endl; 
    
    return 0;
}
```

<h1>Instrukcje sterujące</h1>

<h4>If</h4>

Instrukcja warunkowa <i> if </i> pozwala na wykonanie części kodu tylko, gdy spełniony jest dany warunek.

```c++
if (warunek)
	kod jaki ma zostac wykonany gdy warunek jest spełniony
```

lub

```c++
if (warunek)
	blok kodu jaki ma zostac wykonany gdy warunek jest spełniony

else
	blok kodu jaki ma zostac wykonany gdy warunek nie jest spełniony
```

Kod jaki umieścimy po warunku powinien być zamknięty między nawiasy klamrowe, bądź składać się jedynie z pojedynczej linii.

```c++
#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	if (n % 3 == 0)
		cout << "Liczba " << n << " jest podzielna przez 3 " << endl;
	else {
		n++;
		cout << "Wczytana liczba powiększona o 1 to: " << n << endl;
	}

	return 0;
}
```

<h4> Wielokrotne warunki </h4>
Możemy sprawdzić wiele warunków jeden po drugim i uzleżnić od ich spełnienia różne bloki kodu.

```c++
#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Podaj numer dnia tygodnia: " << endl;
	cin >> n;
	
	if (n == 0)
		cout << "Poniedziałek." << endl;
		
	else if (n == 1)
		cout << "Wtorek." << endl;

	else if (n == 2)
		cout << "Środa. " << endl;
		
	else if (n == 3)
		cout << "Czwartek." << endl;
		
	else if (n == 4)
		cout << "Piątek." << endl;
		
	else if (n == 5)
		cout << "Sobota." << endl;
		
	else if (n == 6)
		cout << "Niedziela." << endl;
	else
		cout << "Error! " << endl;

	return 0;
}
```


<h4>Switch</h4>

<i>Switch</i> daje nam również możliwość sprawdzenia wielokrotnych warunków. </br>
We współczesnych kompilatorach będzie zazwyczaj szybszy niż <i>else if</i>. </br>
Jest również uważany za bardziej elegancki.

```c++
#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Podaj numer dnia tygodnia: " << endl;
	cin >> n;
	
	switch (n) {
		case 0:
			cout << "Poniedziałek." << endl;
			break;
	
		case  1:
			cout << "Wtorek." << endl;
			break;

		case 2:
			cout << "Środa. " << endl;
			break;
		
		case 3:
			cout << "Czwartek." << endl;
			break;

		case 4:
			cout << "Piątek." << endl;
			break;

		case 5:
			cout << "Sobota." << endl;
			break;

		case 6:
			cout << "Niedziela." << endl;
			break;

		default:
			cout << "Error! " << endl;
	}
		
	return 0;
}
```

<h1>Pętle</h1>
The for statement repeats the execution of a part of a program.
for(initialisation; condition; increment)
<statement to repeat>

<h4> Pętla for </h4>

<h4> Pętla while </h4>

<h4> Pętla do while </h4>

<h4>Continue </h4>

<h4>Break </h4>

<h1>Liczby losowe</h1>

```c++
#include <random>

int losowa_z_przedzialu(int start, int end){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dist(start,end);
    return distr(gen);
}

//Dwie opcje z równym prawdopodobieństwem
int orzel_lub_reszka(){
    if(randomInRange(-10001, 10000) >= 1){
        return 1;
    }
    return -1;
}
```

<h1>Funkcje</h1>

<h4>Tworzenie i wywoływanie funkcji</h4>
Za pomocą funkcji możemy część kodu zamknąć pod jedną nazwą.

Elementy składowe funkcji to:
1. <em>Typ</em> zwracanej wartości.
2. <em>Imię</em> funkcji, dzięki któremu jest rozpoznawalna.
3. <em>Argumenty</em>, czyli zewnętrzne wartości, które chcemy użyć w funkcji i chcemy żeby zostały nam podane w momencie wywołania funkcji.


```c++
wybrany_typ nazwa_funkcji(argumenty){	
	//ciało czyli jaki kod chcemy żeby został uruchomiony po wywołaniu nazwa_funkcji 	
	return wartosc_jaka_ma_zostac_zwrocona; 

}	

int main(){ 	
	wybrany_typ x = nazwa_funkcji(argumenty); 	
}	
```

<h4>Funkcja void</h4>
Funkcje void nie zwracają żadnej wartości.
Nie używamy słowa kluczowego <em>return</em>.

```c++
#include <iostream>

using namespace std;

void wypisz_imie(string s){
	cout << s << endl;
}

int main() {
	string imie = "Karol";
	wypisz_imie(imie);
	
	return 0;
}
```

<h4>Funkcja zwracająca wartość</h4>
Konieczne jest użycie słowa kluczowego <em>return</em>. </br>
Typ zwracanej wartości powinien zgadzać się z typem umieszczonym przed nazwą funkcji.

```c++
#include <iostream>

using namespace std;

int suma(int x, int y){
	return x + y;
}

int main() {
	int a = 5;
	int b = 3;
	
	cout << suma(a, b) << endl;
	
	return 0;
}	
```

<h4>Parametry z domyślną wartością</h4>

Domyślna wartość to taka, która zostanie użyta jeśli przy wywołaniu funkcji nie otrzymamy danego parametru.

```c++
#include <iostream>

using namespace std;

int pomnoz(int a, int b = 3){
	return a*b;
}

int main() {
	int x = 2;
	int y = 7;
	
	cout << pomnoz(x, y) << endl;
	cout << pomnoz(x) << endl;

	return 0;
}
```

<h4>Funkcje muszą być zadeklarowane przed użyciem</h4>

Jeśli będziemy chcieli użyć funkcji, której nie zadeklarowaliśmy otrzymamy błąd.
Możemy natomiast użyć funkcji, która nie została jeszcze zdefiniowana.

```c++
#include <iostream>

using namespace std;

// deklaracja + definicja
void fun1(){
	cout << "fun1" << endl;
}

// deklaracja
void fun2();

int main() {
	fun1(); // OK
	fun2(); // OK
	fun3(); // ŹLE

	return 0;
}

void fun2(){
	cout << "fun2" << endl;
}

void fun3(){
	cout << "fun3" << endl;
}
```

<h1>Wskaźniki</h1>

Wskaźnik przechowuje adres innej zmiennej.

<h4>Deklaracja</h4>
<p><em>Typ_zmiennej_kt&oacute;rej_adres_przechowuje_wskaźnik * nazwa_wskaźnika;</em></p>

```c++
int* p1;
double* p2;
string* p3;
```
<h4>Inicjalizacja</h4>

```c++
int x = 4;
double y = 3.5;
string s = "napis";

p1 = &x;
p2 = &y;
p3 = &s;
```
<h4>Dereferencja</h4>
Wyłuskanie wartości na, która znajduje się w zmiennej, na którą wskazuje nasz wskaźnik.
Używane nie tylko do odczytu, ale również zmiany wartości tej zmiennej.

<p><em>*nazwa wskaźnika</em></p>

```c++
#include<iostream>
using namespace std;

int main(){
	int x = 4;
	double y = 3.5;
	string s = "napis";
	
	int* p1 = &x;
	double* p2 = &y;
	string* p3 = &s;
  
  	cout << "Co siedzi w zmiennych x, y, s: " << endl;
	cout << p1* << endl;
	cout << p2* << endl;
	cout << p3* << endl;
  
  	*p1 = 7; //zmiana wartosci zmiennej x
	*p2 = 8.123; //zmiana wartosci zmiennej y
  	*p3 = "inny"; //zmiana wartosci zmiennej s

	cout << "Co siedzi w zmiennych x, y, s: " << endl;
	cout << p1* << endl;
	cout << p2* << endl;
	cout << p3* << endl;
  
  	return 0;
}
```

<h1>Tablice</h1>

Jeśli zmienna to pudełko, to tablica to półka z pudełkami. Wszystkie pudełka na jednej półce przechowują dane tego samego typu.

Półka z 3 pudełkami typu int. Miejsce w pamięci zostało zarezerwowane, ale pudełka są niezaincjalizowane. Co siedzi w środku? Śmieci.

```c++
int tab[3];
```
Półka z 3 pudełkami typu int. Tablica zadeklarowana i zainicjalizowana. </br>
Obie wersje dopuszczalne.

```c++
int arrayOfInts[3] = {7, 8, 11};
```
```c++
int arrayOfInts[] = {7, 8, 11};
```

<h4>Wczytywanie i wypisywanie elemntów tablicy </h4>

```c++
#include <iostream>

using namespace std;

const int n = 10;

int main() {

	int a[n];
	
	cout << "Podaj " << n << " elementów: " << endl;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	cout << "Twoja tablica: " << endl;
	
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	
	return 0;
}
```

<h4>Dynamiczna alokacja pamięci </h4>

Aby skorzystać z pamięci sterty, używamy operatora <i>new</i> do alokacji (rezerwacji) miejsc dla elemntów tablicy.
Gdy tablica nie jest nam już potrzebna zarezerwowaną uprzednio pamięć uwalniamy przy pomocy <i>delete</i>.

```c++
#include <iostream>

using namespace std;

int main() {
	
	cout << "Podaj liczbę elemntów tablicy: " << endl;
	
	int n;
	cin >> n;

	int *a = new int[n];
	
	cout << "Podaj " << n << " elementów: " << endl;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	cout << "Twoja tablica: " << endl;
	
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	
	delete[] a;
	
	return 0;
}
```

<h4>Tablica 2D</h4>

Tablice mogą mieć dowolną ilość wymiarów. Najczęściej będzimy spotykać tablice jedno i dwu-wymiarowe.

```c++
#include <iostream>

using namespace std;

int const n = 3;
int const m = 4;

int main() {

	int a[n][m];
	
	cout << "Podaj " << n*m << " elementów: " << endl;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		
	cout << "Twoja tablica: " << endl;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
		
	return 0;
}
```

<h1>Napisy</h1>

Napis (string) to tablica znaków.

<p>&nbsp;Biblioteka <i> <string> </i> zawiera definicje:</p>

<table style="height: 263px; width: 546px;">
<tbody>
<tr>
<td style="width: 155px; text-align: center;"><strong>Funkcja</strong></td>
<td style="width: 385px; text-align: center;"><strong>Działanie</strong></td>
</tr>
<tr>
<td style="width: 155px;">a.size()</td>
<td style="width: 385px;">z ilu znak&oacute;w składa się napis&nbsp;<em>a&nbsp;</em>(długość)</td>
</tr>
<tr>
<td style="width: 155px;">a.clear() </td>
<td style="width: 385px;">wyczyść napis a</td>
</tr>
<tr>
<td style="width: 155px;">a.empty() </td>
<td style="width: 385px;">prawda jeśli napis <em>a</em> jest pusty</td>
</tr>
<tr>
<td style="width: 155px;">a.append("czesc")</td>
<td style="width: 385px;">dostaw "czesc" na koniec napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.insert(0, "hej")</td>
<td style="width: 385px;">wstaw "hej" na pozycje 0 do napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.pop_back() </td>
<td style="width: 385px;">ściągnij ostatni znak z napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.c_str() </td>
<td style="width: 385px;">konwersja&nbsp;<em>a</em> na char *</td>
</tr>
<tr>
<td style="width: 155px;">a.find("lol")</td>
<td style="width: 385px;">na jakiej pozyji w napisie&nbsp;<em>a </em>znajduje się napis "lol"</td>
</tr>
<tr>
<td style="width: 155px;">a.compare(b)</td>
<td style="width: 385px;">&nbsp;por&oacute;wnaj napis&nbsp;<em>a</em> z&nbsp;<em>b</em></td>
</tr>
</tbody>
</table>

<h1>Pole bitowe</h1>

Możemy wskazać ile dokładnie bitów chcemy zarezerwować dla danego pola struktury.

```c++
#include <iostream>

using namespace std;

struct Data {
	unsigned int Rok : 13; // 2^13 = 8192
	unsigned int Miesiac : 4; // 2^4 = 16
	unsigned int Dzien : 5; // 2^5 = 32
};

void wypiszDate(Data d) {
	cout << "Mamy dziś: " << endl;
	cout << d.Dzien << "-" << d.Miesiac << "-" << d.Rok << endl;
}

int main() {
	Data d;
	d.Rok = 2020;
	d.Miesiac = 7;
	d.Dzien = 18;
	
	wypiszDate(d);
	
	return 0;
}
```

<h1>Operacje bitowe</h1>

Mamy możliwość wykonywania operacji na pojedynczych bitach.

<h4> Bramka NOT </h4>

Zamienia zera na jedynki i na odwrót. Operator ~.

<table style="width:100%">
  <tr>
    <th>Wejście</th>
    <th>Wyjście</th>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
</tr>
  <tr>
    <td>1</td>
    <td>0</td>
  </tr>
</table>


```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<8> x(5);
	cout << x << endl; //00000101
	cout << ~x << endl; //11111010

	return 0;
}
```

<h4> Bramka OR </h4>

Jedynka gdy co najmniej jeden z bitów to jedynka, w przeciwnym razie zero. Operator |.

<table style="width:100%">
  <tr>
    <th>Wejście 1</th>
    <th>Wejście 2</th>
    <th>Wyjście</th>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
</tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>1</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
  </tr>
<tr>
    <td>1</td>
    <td>1</td>
    <td>1</td>
  </tr>
</table>

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 7;
	int b = 5;
	
	cout << bitset<8>(a) << endl; //00000111
	cout << bitset<8>(b) << endl; //00000101
	cout << bitset<8>(a | b) << endl; //00000111
	
	return 0;
}
```

<h4> Bramka AND </h4>

Jedynka gdy oba bity to jedynki, w przeciwnym razie zero. Operator &.

<table style="width:100%">
  <tr>
    <th>Wejście 1</th>
    <th>Wejście 2</th>
    <th>Wyjście</th>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
</tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>0</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
  </tr>
<tr>
    <td>1</td>
    <td>1</td>
    <td>1</td>
  </tr>
</table>

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 7;
	int b = 5;
	
	cout << bitset<8>(a) << endl; //00000111
	cout << bitset<8>(b) << endl; //00000101
	cout << bitset<8>(a & b) << endl; //00000101
	
	return 0;
}
```

<h4> Bramka XOR </h4>

Jedynka gdy bity różne, w przeciwnym razie zero. Operator ^.

<table style="width:100%">
  <tr>
    <th>Wejście 1</th>
    <th>Wejście 2</th>
    <th>Wyjście</th>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
</tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>1</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
  </tr>
<tr>
    <td>1</td>
    <td>1</td>
    <td>0</td>
  </tr>
</table>

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 7;
	int b = 5;
	
	cout << bitset<8>(a) << endl; //00000111
	cout << bitset<8>(b) << endl; //00000101
	cout << bitset<8>(a ^ b) << endl; //00000010
	
	return 0;
}
```

<h4> Przesunięcia bitowe </h4>

Bity w lewo przesuwamy za pomocą operatora <<. </br>
Bity w prawo przesuwamy za pomocą operatora >>. </br>
Przesunięcie w lewo o 1 bit równoważne jest podzieleniu przez 2. </br>
Przesuniecie w prawo o 1 bit równoważne jest przemnożeniu przez 2. </br>

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 14;
	int b = 2;
	
	cout << bitset<8>(a) << endl; //00001110
	cout << bitset<8>(b) << endl; //00000010
	cout << bitset<8>(a << b) << endl; //00111000
	cout << bitset<8>(a >> b) << endl; //00000011
	
	return 0;
}
```
<h4>Ustaw wszystkie bity</h4>

Zamiana wszystkich bitów na jedynki.

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 14;
	
	cout << bitset<8>(a) << endl; //00001110
	
	a = -1; // zamienia wszystkie bity na 1
	
	cout << bitset<8>(a) << endl; //11111111
	
	a = 14;
	
	//inny sposob
	cout << bitset<8>(a).set() << endl; //11111111
	
	return 0;
}
```

<h4>Obróć n-ty bit</h4>

Zamień n-ty (licząc od prawej strony) bit na jego przeciwieństwo, czyli jedynkę na zero i na odwrót.

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 14; //00001110
	int n = 2; //00000010

	a ^= 1 << n;
	
	cout << bitset<8>(a) << endl; //00001010
	
	return 0;
}
```

<h4>Sprawdź n-ty bit</h4>

Sprawdź czy n-ty (licząc od prawej strony) bit to zero, czy jedynka.

```c++
#include <iostream>

using namespace std;

int main() {
	int a = 14; //00001110
	int n = 2; //00000010
	
	cout << (a >> n & 1) << endl; //1
	
	return 0;
}
```

<h4>Ustaw n-ty bit</h4>

Wstaw jedynkę na n-te miejsce od końca.

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 8; //00001000
	int n = 2; //00000010

	cout << bitset<8>(a |= 1 << n) << endl; //00001100
	
	return 0;
}
```

<h4>Wyczyść n-ty bit</h4>

```c++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a = 8; //00001000
	int n = 3; //00000011

	cout << bitset<8>(a &= ~(1 << n)) << endl; //00000000
	
	return 0;
}
```

<h4>Sprawdź parzystość liczby</h4>

Wystarczy sprawdzić ostatni bit. Nieparzysta liczba będzie zawsze miała na ostatnim miejscu jedynkę, a parzysta zero.

```c++
#include <iostream>

using namespace std;

int main() {
	int a = 8; //00001000
	int b = 7; //00000111

	cout << (a && !(a & (a - 1))) << endl; //1
	cout << (b && !(b & (b - 1))) << endl; //0
	
	return 0;
}
```

<h1>Iteratory</h1>
	
<h1>Programowanie Obiektowe</h1>

Pisanie programów, w których w interakcje ze sobą wchodzą różne <b>obiekty</b>.

<ol>
	<li> 1. <b>Klasa</b> to szablon, w którym definiujemy <b>pola</b> (jakie dane mogą przechowywać obiekty danej klasy) oraz metody</b> (funkcje coś robiące z tymi polami). </li>
	<li> 2. Zastosowania obiektów danej klasy dane są przez dostępne metody. </li>
</ol>

Dlaczego?

<ol>
	<li> 1. Modularność: każda klasa ma jasno określony cel i wszystko co z nim jest związane zamknięte jest w tej klasie (przynajmniej w teorii).</li> 
	<li> 3. Łatwość wielokrotnego użytku: możemy tworzyć nieskończenie wiele obiektów danej klasy, ograniczają nas jedynie fizyczne możliwości naszej maszyny.</li> 
</ol>

```bash
gcc -std=c99
g++ -std=c++98
sudo apt install clang-format
find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
```
