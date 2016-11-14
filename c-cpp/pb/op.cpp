#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

using namespace std;

void PromptForAddress(tutorial::Person* person);
void ListPeople(const tutorial::AddressBook& address_book);

// read the entire addressbook from a file
// add one person based on user input
// then write it back to the same file
int main(int argc, char* argv[]){
    //verify the version of the library is compatible with the version of the headers
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    //检查参数
    if(argc != 2){
        cerr << "Usage: " << argv[0] << "ADDRESSBOOK_FILE" <<endl;
        return -1;
    }

    tutorial::AddressBook address_book;

    {
        //read the existing address book
        fstream input(argv[1],ios::in | ios::binary);
        if(!input){
            cout << argv[1] << ": File not found. Creating a new file." << endl;
        }else if(!address_book.ParseFromIstream(&input)){
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }
    
    ListPeople(address_book);

    //add an address
    PromptForAddress(address_book.add_person());

    {
        //write the new address book back to disk
        fstream output(argv[1],ios::out | ios::trunc | ios::binary);
        if(!address_book.SerializeToOstream(&output)){
            cerr << "Failed to write address book." << endl;
            return -1;
        }
    }

    //Optional: Delete all global objects allocated by libprotobuf
    //适用:内存泄露检测要求释放最后一个对象
    //在写一个会被单个进程多次加载释放的库
    google::protobuf::ShutdownProtebufLibrary();

    return 0;
}

void PromptForAddress(tutorial::Person* person){
    cout << "Enter person ID number:";
    int id;
    cin >> id;
    person->set_id(id);

    //忽略输入中指定个数的字符，除非遇到指定的终止字符时提前结束
    //在这的作用是清除以回车结束的输入缓冲区的内容
    cin.ignore(256,'\n');
    cout << "Enter name:";
    getline(cin,*person->mutable_name());

    cout << "Enter email address (blank for none):";
    string email;
    getline(cin,email);
    if(!email.empty()){
        person->set_email(email);    
    }

    while(true){
        cout << "Enter a phone number (or leave blank to finish)";
        string number;
        getline(cin,number);
        if(number.empty()){
            break;
        }

        tutorial::Person::PhoneNumber* phone_number = person->add_phone();
        phone_number->set_number(number);

        cout << "Is this a mobile, home, or work phone?";
        string type;
        getline(cin,type);
        if(type == "mobile"){
            phone_number->set_type(tutorial::Person::MOBILE);
        }else if(type == "home"){
            phone_number->set_type(tutorial::Person::HOME);
        }else if(type == "work"){
            phone_number->set_type(tutorial::Person::WORK);
        }else{
            cout << "Unknown phone type. Using default." << endl;
        }
    }
}

//Iterates through all people in the AddressBook and prints info about them
void ListPeople(const tutorial::AddressBook& address_book){
    for(int i = 0; i < address_book.person_size();i++){
        const tutorial::Person& person  = address_book.person(i);

        cout << "Person  ID: " << person.id() << endl;
        cout << "Name: " << person.name() << endl;
        if(person.has_email()){
            cout << "E-mail address: " << person.email() << endl;    
        }

        for(int j = 0; j < person.phone_size();j++){
            const tutorial::Person::PhoneNumber& phone_number = person.phone(j);

            switch(phone_number.type()){
                case tutorial::Person::MOBILE:
                    cout << "Mobile phone #: ";
                    break;
                case tutorial::Person::HOME:
                    cout << "Home phone #: ";
                    break;
                case tutorial::Person::WORK:
                    cout << "Work phone #: ";
                    break;
            }
            cout << phone_number.number() << endl;
        }
    }
}
