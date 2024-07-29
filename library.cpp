#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> books;

void addBook(string title) {
    books.push_back(title);
    sort(books.begin(), books.end());
}

bool binarySearch(string title) {
    int left = 0;
    int right = books.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid] == title) {
            return true;
        }
        if (books[mid] < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

void displayBooks() {
    for (const auto &book : books) {
        cout << book << endl;
    }
}

int main() {
    int choice;
    string title;

    while (true) {
        cout << "Library Book Finder" << endl;
        cout << "1. Add a book title" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                addBook(title);
                break;
            case 2:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                if (binarySearch(title)) {
                    cout << "Book found!" << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
