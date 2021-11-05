#include <bits/stdc++.h>

class Animal {
 public:
  Animal();
  virtual ~Animal();
  virtual void Showme() = 0;
  virtual std::string Kind() = 0;
  friend std::istream &operator>>(std::istream &, Animal &);

 protected:
  std::string name_, color_, food_;
  double weight_;
};

Animal::Animal() = default;
Animal::~Animal() = default;
std::istream &operator>>(std::istream &input, Animal &B) {
  std::cout << "input name of the new pet: ";
  input >> B.name_;
  std::cout << std::endl;
  std::cout << "input the color of the new pet: ";
  input >> B.color_;
  std::cout << std::endl;
  std::cout << "input the favorite food of the new pet: ";
  input >> B.food_;
  std::cout << std::endl;
  std::cout << "input the weight(kg) of the new pet: ";
  input >> B.weight_;
  std::cout << std::endl;
  return input;
}

class Cat : public Animal {
 public:
  Cat();
  ~Cat();
  void Showme();
  std::string Kind();
};
Cat::Cat() { std::cin >> *this; }
Cat::~Cat() { return; }
void Cat::Showme() {
  std::cout << "The kind of this pet is cat." << std::endl;
  std::cout << "The name of this pet is " << this->name_ << std::endl;
  std::cout << "The color of this pet is " << this->color_ << std::endl;
  std::cout << "The weight of this pet is " << this->weight_ << std::endl;
  std::cout << "The favorite food of this pet is " << this->food_ << std::endl;
}
std::string Cat::Kind() { return std::string("cat"); }

class Dog : public Animal {
 public:
  Dog();
  ~Dog();
  void Showme();
  std::string Kind();
};
Dog::Dog() { std::cin >> *this; }
Dog::~Dog() { return; }
std::string Dog::Kind() { return std::string("dog"); }
void Dog::Showme() {
  std::cout << "The kind of this pet is dog." << std::endl;
  std::cout << "The name of this pet is " << this->name_ << std::endl;
  std::cout << "The color of this pet is " << this->color_ << std::endl;
  std::cout << "The weight of this pet is " << this->weight_ << std::endl;
  std::cout << "The favorite food of this pet is " << this->food_ << std::endl;
}

class Snake : public Animal {
 public:
  Snake();
  ~Snake();
  void Showme();
  std::string Kind();
};
Snake::Snake() { std::cin >> *this; }
Snake::~Snake() { return; }

void Snake::Showme() {
  std::cout << "The kind of this pet is snake." << std::endl;
  std::cout << "The name of this pet is " << this->name_ << std::endl;
  std::cout << "The color of this pet is " << this->color_ << std::endl;
  std::cout << "The weight of this pet is " << this->weight_ << std::endl;
  std::cout << "The favorite food of this pet is " << this->food_ << std::endl;
}
std::string Snake::Kind() { return std::string("snake"); }
class Shelves {
 public:
  Shelves();
  ~Shelves();
  void AddTo(Animal *new_comer, int position);
  void Remove(int position);
  void Query(int position);
  void Count();
  void PrintCageList();

 private:
  static const int MAX_CAGES = 12;
  Animal *cages_[MAX_CAGES];
};

Shelves::Shelves() {
  for (int i = 0; i < MAX_CAGES; i++) {
    cages_[i] = nullptr;
  }
}
Shelves::~Shelves() {
  for (int i = 0; i < MAX_CAGES; i++) {
    if (cages_[i] != nullptr) {
      delete cages_[i];
      cages_[i] = nullptr;
    }
  }
}

void Shelves::AddTo(Animal *new_comer, int position) {
  if (cages_[position] == nullptr)
    cages_[position] = new_comer;
  else
    std::cerr << "Operation failed: This cage has already held a pet!"
              << std::endl;
}

void Shelves::Remove(int position) {
  if (cages_[position] != nullptr) {
    cages_[position] = nullptr;
  } else {
    std::cerr << "Operation failed: This cage has not held a pet!" << std::endl;
  }
}

void Shelves::Query(int position) {
  if (cages_[position] == nullptr) {
    std::cout << "This is an empty cage!";
  } else {
    cages_[position]->Showme();
  }
}

void Shelves::Count() {
  int cats = 0, dogs = 0, snakes = 0, emptys = 0;
  for (int i = 0; i < MAX_CAGES; i++) {
    if (cages_[i] == nullptr) {
      emptys++;
    } else {
      if (cages_[i]->Kind() == std::string("cat")) {
        cats++;
      } else if (cages_[i]->Kind() == std::string("dog")) {
        dogs++;
      } else if (cages_[i]->Kind() == std::string("snake")) {
        snakes++;
      }
    }
  }
  std::cout << "Emptys Cages: " << emptys << std::endl;
  std::cout << "Cats: " << cats << std::endl;
  std::cout << "Dogs: " << dogs << std::endl;
  std::cout << "Snakes: " << snakes << std::endl;
}

void Shelves::PrintCageList() {
  std::cout << "---------------------------------" << std::endl;
  for (int i = 0; i < MAX_CAGES; i++) {
    std::cout << "cages " << i << ": " << std::endl;
    if (cages_[i] == nullptr) {
      std::cout << "This is an empty cage." << std::endl;
    } else {
      cages_[i]->Showme();
    }
    std::cout << "---------------------------------" << std::endl;
  }
}

void InfoBar() {
  std::cout << std::endl << std::endl;
  std::cout << "Select an operation:" << std::endl;
  std::cout << "0. Exit the program." << std::endl;
  std::cout << "1. Add a new pet into an empty cage." << std::endl;
  std::cout << "2. Remove the pet from a cage." << std::endl;
  std::cout << "3. Query a pet from one cage." << std::endl;
  std::cout << "4. Count pets in all the cages." << std::endl;
  std::cout << "5. Print the cage list." << std::endl;
}

template <class T>
void StdInput(const char *info, T &input) {
  std::cout << info;
  std::cin >> input;
  std::cout << std::endl;
}

void Test() {
  int op, pos;
  std::string kind;
  Animal *pet = nullptr;
  Shelves shelf;
  while (1) {
    InfoBar();
    std::cin >> op;
    switch (op) {
      case 0:
        return;
        break;
      case 1:
        StdInput("input the kind of the new pet: ", kind);
        if (kind == std::string("cat")) {
          pet = new Cat();
        } else if (kind == std::string("dog")) {
          pet = new Dog();
        } else if (kind == std::string("snake")) {
          pet = new Snake();
        } else {
          std::cout << "Error: Invalid kind!" << std::endl;
        }
        StdInput("select a cage for the new pet: ", pos);
        if (pet != nullptr) shelf.AddTo(pet, pos);
        break;
      case 2:
        StdInput("select a cage for the new pet: ", pos);
        shelf.Remove(pos);
        break;
      case 3:
        StdInput("select a cage to query: ", pos);
        shelf.Query(pos);
        break;
      case 4:
        shelf.Count();
        break;
      case 5:
        shelf.PrintCageList();
        break;
      default:
        pet = nullptr;
    }
  }
}

int main() {
  Test();
  return 0;
}
