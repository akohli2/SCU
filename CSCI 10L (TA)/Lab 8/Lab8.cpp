#include <iostream>
#include <string>

using namespace std;

//A1

struct date {
  int month;
  int day;
  int year;
};

struct Item {
  string name;
  string author;
  double price;
  string content[100];
  int size;
  date RD;
  string dummy;
};

//A3

void printItem(Item it) {
  cout << "Name: " << it.name << endl;
  cout << "Author/Artist: " << it.author << endl;
  cout << "Price: " << it.price << endl;
  for (int i = 0; i < it.size; i++) {
    cout << "Songs/Chapters: " << it.content[i];
  }
  cout << "Release Date: " << it.RD.month << "/" << it.RD.day << "/" << it.RD.year << endl;
}

void initializeItem(Item& it) {
  cout << "What is title of book/album?" << endl;
  getline(cin,it.name);
  cout << "What is author/artist name?" << endl;
  getline(cin,it.author);
  cout << "What is its price?" << endl;
  cin >> it.price;
  cout << "How many chapters/songs are in it?" << endl;
  cin >> it.size;
  getline(cin,it.dummy);
  for (int i = 0; i < it.size; i++) {
    cout << "What is name of song/chapter " << i+1 << " ?" << endl;
    getline(cin,it.content[i]);
  }
}

int main() {
  Item it;
  initializeItem(it);
  printItem(it);

}

//A5

double fillCart(Item a[], int size) {
  double total = 0;
  for (int i = 0; i < size; i++) {
    cout << "Item: " << a[i].name << ", by " << a[i].author << " for $" << a[i].price << endl;
    cout << "Would you like to \"purchase\", see more \"details\", or \"pass\"?" << endl;
    string s;
    cin >> s;
    if (s == "pass") {

    } else if (s == "details") {
      printItem(a[i]);
      cout << "Would you like to \"purchase\" or \"pass\"?" << endl;
      string s2;
      cin >> s2;
      if (s2 == "purchase") {
        total = total + a[i].price;
      } else if (s2 == "pass") {

      }
    } else if (s == "purchase") {
        total = total + a[i].price;
    }
  }
  return total;
}

int main()
{
    Item arr[3] = {{"Slaughterhouse 5", "Kurt Vonnegut", 7.99},
    {"Let it Be", "The Replacements", 11.49,{"I Will Dare", "Favorite Thing", "We're Comin' Out",
            "Tommy Gets His Tonsils Out","Androgynous","Black Diamond","Unsatisfied",
            "Seen Your Video","Gary's Got","Sixteen Blue","Answering Machine"}, 11, {10, 2, 1984}},
    {"Let it Be", "The Beatles", 16.29, {"Two Of Us", "Dig A Pony","Across The Universe",
            "I Me Mine","Dig It","Let It Be","Maggie Mae","I've Got A Feeling","One After 909",
            "The Long And Winding Road","For You Blue","Get Back"}, 12, {5, 11, 1970}}};
    double cost = fillCart(arr, 3);
    cout<<"Total cost: "<<cost;
    return 0;
}
