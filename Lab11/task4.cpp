#include <iostream>
#include <exception>

using namespace std;


class DatabaseException : public exception {

        public:

        const char* what() const noexcept {
    return "A database error occurred.";
    }
};


class ConnectionFailedException : public DatabaseException {};

class QueryTimeoutException : public DatabaseException {};

template <class T>

class DatabaseConnector {

public:
    void connect(T database) {

        if (database == "invalid_db")
            throw ConnectionFailedException();

        else if (database == "slow_db")

            throw QueryTimeoutException();
        else
            cout << "Connected to " << database << " successfully!" << endl;
    }
};

int main() {

    DatabaseConnector<string> db;

    cout << "Attempting to connect to invalid_db..." << endl;
    try {
        db.connect("invalid_db");

    } 
    
    catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what()<< endl;
    }

    cout << "Attempting to connect to slow_db..." << endl;

    try {
        db.connect("slow_db");

    } 
    
    catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
