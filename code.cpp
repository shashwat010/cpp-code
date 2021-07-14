#include <bits/stdc++.h>

using namespace std;

string computerTurn(vector<string> &cards, string topCard)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i][0] == topCard[0] || cards[i][1] == topCard[1])
        {
            string temp = cards[i];
            cards.erase(cards.begin() + i);
            return temp;
        }
    }
    return "no";
}

void playerCall(int i)
{
    if (i == 0)
        cout << "Player 1 play your card : ";
    else
        cout << "Player " << i + 1 << " turn\n";
}

void shuffle(vector<string> &total_cards)
{
    // Initialize seed randomly
    srand(time(0));
    for (int i = 0; i < 40; i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (40 - i));

        swap(total_cards[i], total_cards[r]);
    }
}

int main()
{
    vector<string> total_cards{"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "RS",
                               "B0",
                               "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BS",
                               "G0",
                               "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "GS",
                               "Y0",
                               "Y1", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9", "YS"};

    vector<string> cards(40);
    int cnt = 40;
    for (int i = 0; i < 40; i++)
    {
        cards[i] = total_cards[i];
    }

    vector<string> P1(7), P2(7), P3(7);

    shuffle(total_cards);
    cout << "The cards has been shuffled!" << endl;
    cout << "You are player 1 and these are your cards." << endl;

    srand(time(NULL));
    for (int j = 0; j < 7; j++)
    {
        P1[j] = cards[rand() % cnt];
        cnt--;
        cards.erase(find(cards.begin(), cards.end(), P1[j]));

        cout << P1[j] << " ";
    }
    cout << endl;

    srand(time(NULL));
    for (int j = 0; j < 7; j++)
    {
        P2[j] = cards[rand() % cnt];
        cnt--;
        cards.erase(find(cards.begin(), cards.end(), P2[j]));
        // cout << P2[j] << " ";
    }
    // cout << endl;

    srand(time(NULL));
    for (int j = 0; j < 7; j++)
    {
        P3[j] = cards[rand() % cnt];
        cnt--;
        cards.erase(find(cards.begin(), cards.end(), P3[j]));
        // cout << P3[j] << " ";
    }
    // cout << endl;
    string topCard = cards[rand() % cnt], temp, emp = "no";
    int i = 0;
    cout << topCard << "\n";

    while (P1.size() != 0 && P2.size() != 0 && P3.size() != 0)
    {
        if (i == 0)
        {
            playerCall(i);
            for (int i = 0; i < P1.size(); i++)
                cout << P1[i] << " ";
            cout << '\n';
            cin >> temp;
            if (temp != emp && temp[0] != topCard[0] && temp[1] != topCard[1])
            {
                cout << "Wrong Move!! Please try again!\n";
                cin >> temp;
            }
            if (temp != emp && temp[0] != topCard[0] && temp[1] != topCard[1])
            {
                cout << "You are not playing according to rules.\nYou Lost!!\nGame ended!!\n";
                return 0;
            }

            if (temp != emp)
            {
                cards.push_back(topCard);
                cnt++;
                topCard = temp;
                if (temp[1] == 'S')
                {
                    i = (i + 1) % 3;
                    playerCall(i);
                    cout << "Skipped\n";
                }
                auto it = find(P1.begin(), P1.end(), temp);
                P1.erase(it);
            }
            else
            {
                P1.push_back(cards[rand() % cnt]);
                cards.erase(find(cards.begin(), cards.end(), P1.back()));
                cnt--;
            }
            if (P1.size() == 0)
            {
                cout << "Congo 1 WINS!!!";
                break;
            }
        }

        else if (i == 1)
        {
            playerCall(i);
            string temp1 = computerTurn(P2, topCard);
            cout << temp1 << "\n";
            if (temp1[1] == 'S')
            {
                i = (i + 1) % 3;
                playerCall(i);
                cout << "Skipped\n";
            }
            if (temp1 != emp)
            {
                cards.push_back(topCard);
                cnt++;
                topCard = temp1;
            }
            else
            {
                P2.push_back(cards[rand() % cnt]);
                cards.erase(find(cards.begin(), cards.end(), P2.back()));
                cnt--;
            }
            if (P2.size() == 0)
            {
                cout << "Congo 2 WINS!!!";
                break;
            }
        }

        else if (i == 2)
        {
            playerCall(2);
            string temp2 = computerTurn(P3, topCard);
            cout << temp2 << "\n";
            if (temp2[1] == 'S')
            {
                i = (i + 1) % 3;
                playerCall(i);
                cout << "Skipped\n";
            }
            if (temp2 != emp)
            {
                cards.push_back(topCard);
                cnt++;
                topCard = temp2;
            }
            else
            {
                P3.push_back(cards[rand() % cnt]);
                cards.erase(find(cards.begin(), cards.end(), P3.back()));
                cnt--;
            }
            if (P3.size() == 0)
            {
                cout << "Congo 3 WINS!!!";
                break;
            }
        }
        i = (i + 1) % 3;
    }
    return 0;
}