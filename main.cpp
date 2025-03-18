#include <bits/stdc++.h>

using namespace std;

struct Team
{
    int T_ID{};
    string T_Name;
    string T_President;
    Team *next_T{};
};

Team *T_head = nullptr;

//************************
struct Player
{
    int P_ID{};
    string P_Name;
    string T_Name;
    string P_Position;
    int P_age{};
    int P_salary{};
    Player *next_P{};
};

Player *P_head = nullptr;

//*****************************

bool is_Empty()
{
    return (T_head == nullptr);
}

//****************************
// check if id already inserted of team
bool preinsert_t(int id)
{
    Team *tep = T_head;
    while (tep != nullptr)
    {
        if (id == tep->T_ID)
        {
            return true;
        }
        tep = tep->next_T;
    }
    return false;
}

// Insert New Team

void insert(int Id, string name, string President)
{
    if (preinsert_t(Id))
    {
        cout << "This Team Already Inserted \n \n";
    }
    else
    {

        Team *new_team = new Team;
        new_team->T_ID = Id;
        new_team->T_Name = std::move(name);
        new_team->T_President = std::move(President);
        new_team->next_T = nullptr;

        if (is_Empty())
        {
            T_head = new_team;
        }
        else
        {
            Team *temp = T_head;
            while (temp->next_T != nullptr)
            {
                temp = temp->next_T;
            }
            temp->next_T = new_team;
        }
    }
}

// Display All Teams
void display()
{
    Team *temp1 = T_head;
    if (is_Empty())
    {
        cout << "No Team Inserted" << endl
             << endl;
    }
    else
    {
        while (temp1 != nullptr)
        {
            cout << "Team ID :" << temp1->T_ID << '\n';
            cout << "Team Name :" << temp1->T_Name << '\n';
            cout << "Team President :" << temp1->T_President << '\n';
            cout << endl;
            cout << "-----------------------------\n";
            temp1 = temp1->next_T;
        }
        cout << "This was all the Egyptian Premier League teams" << endl
             << endl;
    }
}

// Search Team By ID
void search(int id)
{
    Team *temp2 = T_head;
    int c = 0;
    if (is_Empty())
    {
        cout << "No Team Inserted Yet" << endl
             << endl;
    }
    else
    {
        while (temp2 != nullptr)
        {
            if (id == temp2->T_ID)
            {
                c++;
                cout << "Team ID :" << temp2->T_ID << '\n';
                cout << "Team Name :" << temp2->T_Name << '\n';
                cout << "Team President :" << temp2->T_President << '\n';
                cout << endl;
            }
            temp2 = temp2->next_T;
        }
        if (c == 0)
            cout << "this team not found \n";
    }
}

// search team by name
bool search_t_name(const string &name)
{
    Team *temp2 = T_head;
    if (is_Empty())
    {
        cout << "No Team Inserted Yet" << endl
             << endl;
    }
    else
    {
        while (temp2 != nullptr)
        {
            if (name == temp2->T_Name)
            {

                return true;
            }
            temp2 = temp2->next_T;
        }
    }
    return false;
}

// Remove Team

void removeTeam(int id)
{
    if (is_Empty())
    {
        cout << "No Teams To Remove\n";
        return;
    }

    // Remove players associated with the team
    Player *tempPlayer = P_head;
    Player *prevPlayer = nullptr;

    while (tempPlayer != nullptr)
    {
        if (tempPlayer->T_Name == T_head->T_Name)
        {
            Player *toRemove = tempPlayer;
            if (prevPlayer == nullptr)
            {
                P_head = tempPlayer->next_P;
            }
            else
            {
                prevPlayer->next_P = tempPlayer->next_P;
            }
            tempPlayer = tempPlayer->next_P;
            delete toRemove;
        }
        else
        {
            prevPlayer = tempPlayer;
            tempPlayer = tempPlayer->next_P;
        }
    }

    // Remove the team
    if (T_head->T_ID == id)
    {
        Team *temp = T_head;
        T_head = T_head->next_T;
        delete temp;
        cout << "Team and associated players removed successfully\n";
    }
    else
    {
        Team *temp = T_head;
        while (temp->next_T != nullptr && temp->next_T->T_ID != id)
        {
            temp = temp->next_T;
        }

        if (temp->next_T == nullptr)
        {
            cout << "No Teams To Remove\n";
        }
        else
        {
            Team *toRemove = temp->next_T;
            temp->next_T = temp->next_T->next_T;
            delete toRemove;
            cout << "Team and associated players removed successfully\n";
        }
    }
}

/*************************player******************************/

bool is_Empty_P()
{
    return (P_head == nullptr);
}

// check if id already inserted of player
bool preinsert_p(int id)
{
    Player *tep = P_head;
    while (tep != nullptr)
    {
        if (id == tep->P_ID)
        {
            return true;
        }
        tep = tep->next_P;
    }
    return false;
}

// Insert New Player
void insert_P(int Id, int age, int salary, string name, string Position, string teamName)
{
    if (preinsert_p(Id))
    {
        cout << "This ID Already Before \n \n\n";
    }
    else
    {
        auto *new_player = new Player;
        new_player->P_ID = Id;
        new_player->P_Name = std::move(name);
        new_player->T_Name = std::move(teamName);
        new_player->P_salary = salary;
        new_player->P_age = age;
        new_player->P_Position = std::move(Position);
        new_player->next_P = nullptr;

        if (is_Empty_P())
        {
            P_head = new_player;
        }
        else
        {
            Player *temp3 = P_head;
            while (temp3->next_P != nullptr)
            {
                temp3 = temp3->next_P;
            }
            temp3->next_P = new_player;
        }
    }
}

// Remove a player.

void removePlayer(int id)
{
    if (is_Empty_P())
    {
        cout << "No Players To Remove\n";
    }
    else
    {

        if (P_head->P_ID == id)
        {
            Player *temp = P_head;
            P_head = P_head->next_P;
            delete temp;
            cout << "Player Removed Successfully\n";
        }

        Player *temp = P_head;
        while (temp->next_P != nullptr && temp->next_P->P_ID != id)
        {
            temp = temp->next_P;
        }

        if (temp->next_P == nullptr)
        {
            cout << "No Players To Remove\n";
        }
        else
        {
            Player *toRemove = temp->next_P;
            temp->next_P = temp->next_P->next_P;
            delete toRemove;
            cout << "Player Removed Successfully\n";
        }
    }
}

// Display All Players
void display_P()
{
    Player *temp5 = P_head;
    if (is_Empty_P())
    {
        cout << "No Player Data Inserted Yet\n";
        cout << endl;
    }
    else
    {
        while (temp5 != nullptr)
        {
            cout << "Player Id : " << temp5->P_ID << '\n';
            cout << "Player Name : " << temp5->P_Name << '\n';
            cout << "Team Name : " << temp5->T_Name << '\n'; // Display Team Name
            cout << "Player Position : " << temp5->P_Position << '\n';
            cout << "Player Age : " << temp5->P_age << '\n';
            cout << "Player Salary : " << temp5->P_salary << '\n';
            cout << "-----------------------------\n";
            temp5 = temp5->next_P;
        }

        cout << "This Was All The Egyptian Premier League Teams" << endl
             << endl;
    }
}

// Search Player By Name
void search_P(const string &name)
{

    if (is_Empty_P())
    {
        cout << "No Player Data Inserted Yet\n"
             << endl;
    }
    else
    {
        Player *temp6 = P_head;
        int c = 0;
        while (temp6 != nullptr)
        {
            if (name == temp6->P_Name)
            {
                cout << "Player Id : " << temp6->P_ID << '\n';
                cout << "Player Name : " << temp6->P_Name << '\n';
                cout << "Team Name : " << temp6->T_Name << '\n'; // Display Team Name
                cout << "Player Position : " << temp6->P_Position << '\n';
                cout << "Player Age : " << temp6->P_age << '\n';
                cout << "Player Salary : " << temp6->P_salary << '\n';
                cout << "-----------------------------\n";
                c++;
            }
            temp6 = temp6->next_P;
        }
        if (c == 0)
        {
            cout << "No Data Found\n";
        }
        return;
    }
}
//	update Team Info For Player

void upd_Player(int playerId, const string &newTeamName)
{
    if (is_Empty_P())
    {
        cout << "No Player Data Inserted Yet\n"
             << endl;
    }
    else
    {
        Player *temp = P_head;
        while (temp != nullptr)
        {
            if (temp->P_ID == playerId)
            {
                if (search_t_name(newTeamName))
                {
                    temp->T_Name = newTeamName;
                    cout << "Team information updated successfully for Player ID " << playerId << endl;
                    return;
                }
                else
                {
                    cout << "team name not found\n";
                    return;
                }
            }
            temp = temp->next_P;
        }
        cout << "Player not found\n";
    }
}

// Display players of a team ordered by their salaries.
void displayPlayersBySalary(const string &teamName)
{
    // Collect players of the specified team

    Player *teamHead = nullptr;
    Player *temp = P_head;
    while (temp != nullptr)
    {
        if (temp->T_Name == teamName)
        {
            // Insert the player into the team's linked list
            auto *newPlayer = new Player(*temp);
            newPlayer->next_P = teamHead;
            teamHead = newPlayer;
        }
        temp = temp->next_P;
    }

    if (teamHead == nullptr)
    {
        cout << "No players found for Team " << teamName << endl;
        return;
    }

    // Sort players by salary in descending order

    for (Player *i = teamHead; i != nullptr; i = i->next_P)
    {
        for (Player *j = i->next_P; j != nullptr; j = j->next_P)
        {
            if (i->P_salary < j->P_salary)
            {
                swap(i->P_ID, j->P_ID);
                swap(i->P_Name, j->P_Name);
                swap(i->P_Position, j->P_Position);
                swap(i->P_age, j->P_age);
                swap(i->P_salary, j->P_salary);
            }
        }
    }

    // Display sorted players
    cout << "Players of Team " << teamName << " ordered by salary:\n";
    for (Player *player = teamHead; player != nullptr; player = player->next_P)
    {
        cout << "Player ID: " << player->P_ID << '\n';
        cout << "Player Name: " << player->P_Name << '\n';
        cout << "Position: " << player->P_Position << '\n';
        cout << "Age: " << player->P_age << '\n';
        cout << "Salary: " << player->P_salary << '\n';
        cout << "-----------------------------\n";
    }

    // Release memory allocated for the team's linked list
    while (teamHead != nullptr)
    {
        Player *nextPlayer = teamHead->next_P;
        delete teamHead;
        teamHead = nextPlayer;
    }
}

//   display Teams By Average Age

void displayTeamsByAverageAge()
{
    // Check if there are no teams or players
    if (is_Empty() || is_Empty_P())
    {
        cout << "No teams or players found.\n";
        return;
    }

    // Create a vector to store team information (ID, Name, Average Age)
    vector<pair<int, pair<string, double>>> teamsInfo;

    // Iterate through teams
    Team *tempTeam = T_head;
    while (tempTeam != nullptr)
    {
        string teamName = tempTeam->T_Name;
        int totalAge = 0, playerCount = 0;

        // Iterate through players to calculate total age and count
        Player *tempPlayer = P_head;
        while (tempPlayer != nullptr)
        {
            if (tempPlayer->T_Name == teamName)
            {
                totalAge += tempPlayer->P_age;
                playerCount++;
            }
            tempPlayer = tempPlayer->next_P;
        }

        // Calculate average age for the team
        double averageAge = (playerCount > 0) ? static_cast<double>(totalAge) / playerCount : 0;

        // Store team information in the vector
        teamsInfo.push_back({tempTeam->T_ID, {teamName, averageAge}});

        tempTeam = tempTeam->next_T;
    }

    sort(teamsInfo.begin(), teamsInfo.end(), [](const auto &a, const auto &b)
         { return a.second.second < b.second.second; });

    cout << "Teams ordered by average player age:\n";
    for (const auto &teamInfo : teamsInfo)
    {
        cout << "Team ID: " << teamInfo.first << '\n';
        cout << "Team Name: " << teamInfo.second.first << '\n';
        cout << "Average Player Age: " << teamInfo.second.second << '\n';
        cout << "-----------------------------\n";
    }
}

//******************************************************************************************************************

int main()
{
    int choose, choose2, id_te, id_p, age, salary;
    string name_te, president, name, Position, teamName, newteam;
    insert(1, "one piece", "seif");
    insert(2, "zamalek", "omar");
    insert(3, "alahly", "7arbi");
    insert_P(1, 19, 4500, "seif ezz", "am", "one piece");
    insert_P(2, 21, 7400, "ahmed 7arbi", "cf", "alahly");
    insert_P(3, 20, 3700, "3mora", "joker", "zamalek");
    insert_P(4, 23, 2800, "3bass", "gk", "one piece");
    insert_P(5, 19, 10200, "t7ena big", "bl", "zamalek");
    insert_P(6, 28, 9800, "t7ena small", "joker", "one piece");
    insert_P(7, 25, 10900, "za3ter", "ss", "alahly");

    /************************************************************************************************/

    while (true)
    {
        cout << "choose one of the following : \n"
                "					1 - Team	\n"
                "					2 - Player  \n"
                "					0 - quit\n";

        cin >> choose;
        cout << endl;

        if (choose == 1)
        {
        jump:
            cout << "choose one of the following : \n"
                    "					1 - Add new team  \n"
                    "					2 - Display team  \n"
                    "					3 - Search for team by ID \n"
                    "					4 - Remove Team By Id\n"
                    "					5 - display Teams By Average Age\n"
                    "					0 - Cancel\n";
            cin >> choose2;
            cout << endl;
            switch (choose2)
            {
            case 1:
                cout << "Enter Team ID : ";
                cin >> id_te;
                cout << "Enter Team Name : ";
                cin.ignore();
                getline(cin, name_te);

                cout << "Enter Team President : ";
                getline(cin, president);
                insert(id_te, name_te, president);

                cout << endl;
                system("pause");
                cout << endl;

                goto jump;

            case 2:
                display();

                cout << endl;
                system("pause");
                cout << endl;

                goto jump;

            case 3:
                if (is_Empty())
                {

                    cout << "no team inserted yet \n \n";

                    system("pause");
                    cout << endl;

                    goto jump;
                }
                else
                {

                    cout << "Enter Team ID : ";
                    cin >> id_te;
                    search(id_te);

                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump;
                }
            case 4:
                if (is_Empty())
                {

                    cout << "no team inserted yet to remove  \n";

                    system("pause");
                    cout << endl;

                    goto jump;
                }
                else
                {
                    cout << "Enter Team ID: ";
                    cin >> id_te;
                    removeTeam(id_te);

                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump;
                }
            case 5:
                if (is_Empty())
                {

                    cout << "no team inserted yet to remove  \n";

                    system("pause");
                    cout << endl;

                    goto jump;
                }
                else
                {

                    displayTeamsByAverageAge();
                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump;
                }
            case 0:
                break;
            default:
                cout << "Inserted number is wrong ";

                cout << endl;
                system("pause");
                cout << endl;

                goto jump;
            }
        }

        //******************************************************

        else if (choose == 2)
        {
        jump1:
            cout
                << "Choose one of the following : \n"
                   "					1 - Add new Player	\n"
                   "					2 - Remove a player \n"
                   "					3 - Display Player Data  \n"
                   "					4 - Search for Player by Name \n"
                   "					5 - Update Team Information \n"
                   "					6 - Display players of a team ordered by their salaries\n"
                   "					0 - Cancel\n";
            cin >> choose2;
            cout << endl;
            switch (choose2)
            {
            case 1:
                if (is_Empty())
                {
                    cout << "no fucking team found ^_^" << endl;
                    cout << endl;
                    system("pause");
                    cout << endl;
                    goto jump1;
                }
                else
                {

                    cout << "Enter Player ID : ";
                    cin >> id_p;
                    cout << "Enter Player Name : ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Player Team Name : ";
                    getline(cin, teamName);
                    cout << "Enter Player Position : ";
                    getline(cin, Position);
                    cout << "Enter Player Age : ";
                    cin >> age;
                    cout << "Enter Player Salary : ";
                    cin >> salary;

                    if (search_t_name(teamName))
                    {

                        insert_P(id_p, age, salary, name, Position, teamName);
                        cout << endl;
                        system("pause");
                        cout << endl;

                        goto jump1;
                    }
                    else
                    {
                        cout << endl;
                        cout << "the inserted team not found in team list \n";
                        cout << endl;
                        system("pause");
                        cout << endl;
                        goto jump1;
                    }
                }
            case 2:
                if (is_Empty_P())
                {

                    cout << "no player found to search yet \n";
                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }
                else
                {
                    cout << "Enter Player ID : ";
                    cin >> id_p;
                    removePlayer(id_p);

                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }
            case 3:
                display_P();

                cout << endl;
                system("pause");
                cout << endl;

                goto jump1;

            case 4:
                if (is_Empty_P())
                {

                    cout << "no player found to search yet \n";
                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }
                else
                {

                    cout << "Enter Player Name : ";
                    cin.ignore();
                    getline(cin, name);
                    search_P(name);

                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }

            case 5:
                if (is_Empty_P())
                {

                    cout << "no player found to search yet \n";
                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }
                else
                {
                    cout << "Enter id For Player : ";
                    cin >> id_p;
                    cout << "Enter New Team  For selected Player : ";
                    cin.ignore();
                    getline(cin, newteam);
                    upd_Player(id_p, newteam);

                    cout << endl;
                    system("pause");
                    cout << endl;

                    goto jump1;
                }
            case 6:
                if (is_Empty())
                {
                    cout << "no team found to search" << endl;
                }
                else if (is_Empty_P())
                {
                    cout << "no team Player to search" << endl;
                }
                else
                {
                    cout << "Enter Team Name: ";
                    cin.ignore();
                    getline(cin, teamName);
                    displayPlayersBySalary(teamName);
                }
                cout << endl;
                system("pause");
                cout << endl;

                goto jump1;

            case 0:
                break;
            default:
                cout << "Inserted number is wrong ";

                cout << endl;
                system("pause");
                cout << endl;

                goto jump1;
            }
        }
        else if (choose == 0)
        {
            return 0;
        }
    }
}