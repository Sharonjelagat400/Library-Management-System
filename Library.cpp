#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    int year;
    string isbn;
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    // Add book to library
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    // Display all books in library
    void displayBooks() {
        cout << "Library Books:" << endl;
        if (books.empty()) {
            cout << "No books in library." << endl;
        } else {
            for (const auto& book : books) {
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Year: " << book.year << endl;
                cout << "ISBN: " << book.isbn << endl << endl;
            }
        }
    }

    // Search for a book by title
    void searchBook(const string& title) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found:" << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Year: " << book.year << endl;
                cout << "ISBN: " << book.isbn << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    // Update book information
    void updateBook(const string& title, const Book& updatedBook) {
        for (auto& book : books) {
            if (book.title == title) {
                book = updatedBook;
                cout << "Book information updated successfully!" << endl;
                return;
            }
        }
        cout << "Book not found. Information not updated." << endl;
    }

    // Delete book from library
    void deleteBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found. Deletion failed." << endl;
    }
};

int main() {
    Library library;

    // Adding sample books to the library
    library.addBook({"The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-0743273565"});
    library.addBook({"To Kill a Mockingbird", "Harper Lee", 1960, "978-0061120084"});
    library.addBook({"1984", "George Orwell", 1949, "978-0451524935"});

    int choice;
    string title, author, isbn;
    int year;

    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Update Book" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                cout << "Enter ISBN: ";
                cin.ignore();
                getline(cin, isbn);
                library.addBook({title, author, year, isbn});
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                cout << "Enter book title to update: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter updated author: ";
                getline(cin, author);
                cout << "Enter updated publication year: ";
                cin >> year;
                cout << "Enter updated ISBN: ";
                cin.ignore();
                getline(cin, isbn);
                library.updateBook(title, {title, author, year, isbn});
                break;
            case 5:
                cout << "Enter book title to delete: ";
                cin.ignore();
                getline(cin, title);
                library.deleteBook(title);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
