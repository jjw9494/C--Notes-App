#include <iostream>
#include <string>
#include <list>
#include <ctime>

class Notes{
    private:
    int id;
    std::string note;
    bool completed;

    public:
    int getId(){ return id;};
    std::string getNote(){ return note; };
    bool getCompleted(){ return completed; };

    void addNote(std::string addNote){ 
        id = rand() % 100 + 1;
        note = addNote;
        completed = false;
    };

    void addCompleted(){
        completed = true;
    }

};

int main(){

    std::list<Notes> listNotes;
    std::list<Notes>::iterator it;

    std::string cli_input;
    std::string note_input;
    int complete_input;
    int delete_input;
    std::string confirm_delete;

    srand(time(NULL));
    listNotes.clear();
    


    while(1){
    std::cout << "********************************" << std::endl;
    std::cout << std::endl;
    std::string version = "1.0";
    std::cout << "Notes.app - Version: " << version << std::endl;
    std::cout << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------------------" << std::endl;
    for ( it = listNotes.begin(); it != listNotes.end(); it++){
        std::string complete = it->getCompleted() ? "Completed" : "Not Complete";
        std::cout << it->getId() << " | " << it->getNote() << " | " << complete << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "[a]dd note" << std::endl;
    std::cout << "[c]omplete note" << std::endl;
    std::cout << "[d]elete note" << std::endl;
    std::cout << "[q]uit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter selection: ";
    std::cin >> cli_input;
    std::cout << std::endl;

    if(cli_input == "q"){
        break;
    }
    else if (cli_input == "a"){
        std::cout << "Enter note: ";
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, note_input);

        Notes notes;
        notes.addNote(note_input);
        listNotes.push_back(notes);
    }
    else if (cli_input == "c"){
        std::cout << "Enter id to complete: ";
        std::cin >> complete_input;
        std::cout << std::endl;

       for ( it = listNotes.begin(); it != listNotes.end(); it++){ 
            if(it->getId() == complete_input){
                it->addCompleted();
            }
       };
    }
    else if(cli_input == "d"){ 
        std::cout << "Id of note to delete: ";
        std::cin >> delete_input;
        std::cout << std::endl;

        for ( it = listNotes.begin(); it != listNotes.end(); it++){ 
            if(it->getId() == delete_input){
                
                std::string complete = it->getCompleted() ? "Completed" : "Not Complete";
                std::cout << it->getId() << " | " << it->getNote() << " | " << complete << std::endl;
                std::cout << "^ Delete note? [Y/n]: ";
                std::cin >> confirm_delete;
                std::cout << std::endl;

                if(confirm_delete == "y" || confirm_delete == "Y"){
                    it = listNotes.erase(it);
                    std::cout << "Deleted" << std::endl;
                    std::cout << std::endl;
                } 
            }
       }; 
    }
    }
}