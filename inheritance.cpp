#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Base Class
class Media {
	protected:
		string title;
		int id;
	public:
		Media(string t, int i) : title(t), id(i) {}
		virtual void display() const = 0;
		int getId() const {
			return id;
		}
		virtual ~Media() {}
};

// Derived Classes
class Book : public Media {
	string author;
	public:
	Book(string t, int i, string a) : Media(t, i), author(a) {}
	void display() const {
		cout << "Book [ID: " << id << ", Title: " << title << ", Author: " << author << "]\n";
	}
};

class DVD : public Media {
	string director;
	public:
	DVD(string t, int i, string d) : Media(t, i), director(d) {}
	void display() const {
		cout << "DVD [ID: " << id << ", Title: " << title << ", Director: " << director << "]\n";
	}
};

class Magazine : public Media {
	int issueNumber;
	public:
	Magazine(string t, int i, int issue) : Media(t, i), issueNumber(issue) {}
	void display() const {
		cout << "Magazine [ID: " << id << ", Title: " << title << ", Issue: " << issueNumber << "]\n";
	}
};

// Template Library Class (using raw pointers)
template <typename T>
class Library {
	vector<T*> items;  // Storing raw pointers
	public:
	void addItem(T* item) {
		for (const auto& it : items) {
			if (it->getId() == item->getId()) {
				delete item;  // Avoid memory leak
				throw runtime_error("Duplicate ID detected.");
			}
		}
		items.push_back(item);
	}

	void displayItems() const {
		if (items.empty())
			throw runtime_error("No items in library.\n");

		for (const auto& it : items)
			it->display();
	}

	void deleteItem(int id) {
		for (auto it = items.begin(); it != items.end(); ++it) {
			if ((*it)->getId() == id) {
				delete *it; // Free memory
				items.erase(it);
				cout << "Item with ID " << id << " deleted.\n";
				return;
			}
		}
		throw runtime_error("Item with given ID not found.");
	}

	~Library() {
		for (auto& it : items) {
			delete it; // Free all memory on destruction
		}
	}
};

// Main Function
int main() {
	Library<Media> library;

	int choice;
	while (true) {
		cout << "\n--- Library Menu ---\n";
		cout << "1. Add Item\n2. Display All Items\n3. Delete Item by ID\n4. Exit\nChoice: ";
		cin >> choice;

		try {
			if (choice == 1) {
				int type;
				cout << "Select type: 1. Book 2. DVD 3. Magazine: ";
				cin >> type;
				if (type < 1 || type > 3)
					throw invalid_argument("Invalid media type selected.");

				string title;
				int id;
				cout << "Enter title and ID:\n";
				cin.ignore();
				getline(cin, title);
				cin >> id;

				if (type == 1) {
					string author;
					cout << "Enter author: ";
					cin.ignore();
					getline(cin, author);
					library.addItem(new Book(title, id, author)); // Using new
				} else if (type == 2) {
					string director;
					cout << "Enter director: ";
					cin.ignore();
					getline(cin, director);
					library.addItem(new DVD(title, id, director));
				} else if (type == 3) {
					int issue;
					cout << "Enter issue number: ";
					cin >> issue;
					library.addItem(new Magazine(title, id, issue));
				}

			} else if (choice == 2)
				library.displayItems();
			else if (choice == 3) {
				int id;
				cout << "Enter ID to delete: ";
				cin >> id;
				library.deleteItem(id);
			} else if (choice == 4)
				break;
			else
				cout << "Invalid choice.\n";
		} catch (exception& e) {
			cout << "Error: " << e.what() << endl;
		}
	}
	return 0;
}
