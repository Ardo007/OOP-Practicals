#ifndef MENU_H_
#define MENU_H_

class Menu {
    public:
        int displayMenu();

};

int Menu::displayMenu() {
    int choice;
    cout << "**********WELCOME TO NINE BOARD TIC TAC TOE**********\n";
    cout << "choose which game mode you want:\n";
    cout << "1. human vs  human\n";
    cout << "2. human vs random\n";
    cout << "3. human vs AI\n";
    cout << "4. random vs AI\n";
    cout << "5. Quit\n";
    cout << "enter choice: ";
    cin >> choice;

    while(choice < 1 || choice > 5){
        cout  << "invalid choice, please choose again:\n";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;

    case 3:
        return 3;
        break;

    case 4:
        return 4;
        break;

    default:
        cout << "thanks for playing!\n";
        return 5;
        break;
    }
    
}

#endif