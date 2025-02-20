#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct 
{
    int type;
    float value;
    char *whoReceived;
    char *whoSent;
    int flag;
} Transection;

//type
//1. Deposit
//2. Withdrawal
//3. Transference

//flag
//1. If he was who received
//-1. If he was who send

typedef struct 
{
    char *name;
    char codeAccount[17];
    float balance;   
    Transection *bankStat; 
    int num_transactions;
} TAccount;

TAccount *bankSystem;
int num_Accounts = 0;

void menu_options();
void selectedOption(int opSel);
void createAccount();
void makeDeposit();
void makeWithdrawal();
void makeTransference();
void viewBankStatement();
void bankStatOptions();
void validateAllocation(void *ptr);

bool validateCode(char code[]);
bool validateAnyValue(float value);
bool validateInterval(int a, int x ,int b);
bool validateConfirmation(int c);
bool validateWithdrawal(float balnc, float withdrawal);

void displayAllAccounts();
void displayOneAccount();

int main()
{
    int op = 1;

    while(op != 8)
    {
        menu_options();
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
        selectedOption(op);
    }
}

void menu_options()
{
    printf("//      Main Options        //\n");
    printf("|---------------------------------|\n");
    printf("|(1) - Create Account             |\n");
    printf("|(2) - Deposit                    |\n");
    printf("|(3) - Withdrawal                 |\n");
    printf("|(4) - Transference               |\n");
    printf("|(5) - Bank statement             |\n");
    printf("|(6) - Remove Account             |\n");
    printf("|(7) - Show Accounts              |\n");
    printf("|(8) - Exit                       |\n");
    printf("|---------------------------------|\n");
    printf("Choose the option:\n");
}

void selectedOption(int opSel)
{
    switch(opSel)
    {
        case 1:
            createAccount();
            break;
        case 2:
            makeDeposit();
            break;
        case 3:
            makeWithdrawal();
            break;
        case 4:
            makeTransference();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid option!!!\n");
            break;
    }
}

void createAccount()
{
    char strAux[100];

    bankSystem = (TAccount *)realloc(bankSystem, (num_Accounts + 1) * sizeof(TAccount));;
    validateAllocation(bankSystem);

    bankSystem[num_Accounts].bankStat = NULL;  
    bankSystem[num_Accounts].num_transactions = 0;

    printf("Enter the name:\n");
    fflush(stdin);
    gets(strAux);
    bankSystem[num_Accounts].name = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(bankSystem[num_Accounts].name, strAux);
    
    system("cls");

    printf("Enter the account code:\n");
    fflush(stdin);
    gets(bankSystem[num_Accounts].codeAccount);
    
    while(!validateCode(bankSystem[num_Accounts].codeAccount))
    {
        printf("Invalid code!!!Enter again:\n");
        fflush(stdin);
        gets(bankSystem[num_Accounts].codeAccount);
    }

    system("cls");

    printf("Enter the opening balance:\n");
    scanf("%f", &bankSystem[num_Accounts].balance);
    
    while(!validateAnyValue(bankSystem[num_Accounts].balance))
    {
        printf("No negative balences!!!Enter again:\n");
        scanf("%f", &bankSystem[num_Accounts].balance);
    }

    system("cls");

    num_Accounts++;

    printf("Account criated successfully!!!\n");
}

void makeDeposit()
{
    if(num_Accounts == 0)
    {
        printf("There is no accounts to make a deposit!!!\n");
        return;
    }

    int accountSelc;

    printf("Available accounts:\n\n");
    for(int i = 0; i < num_Accounts; i++)
    {
        printf("Account [%d]:\n", i + 1);
        printf("- Name: %s\n", bankSystem[i].name);
        printf("- Code: %s\n", bankSystem[i].codeAccount);
        printf("- Atual balance: %.2f\n\n", bankSystem[i].balance);
    }

    printf("Choose the account to which the deposit will be made:\n");
    scanf("%d", &accountSelc);
    
    while(!validateInterval(1, accountSelc, num_Accounts))
    {
        printf("Again!!!\n");
        scanf("%d", &accountSelc);
    }

    system("cls");

    float deposit;

    printf("How much money will be deposited?\n");
    scanf("%f", &deposit);
    
    while(!validateAnyValue(deposit))
    {
        printf("No negative deposits!!!\n");
        scanf("%f", &deposit);
    }

    bankSystem[accountSelc - 1].balance += deposit;
    
    int transacIndex = bankSystem[accountSelc - 1].num_transactions;

    bankSystem[accountSelc - 1].bankStat = (Transection *)realloc(bankSystem[accountSelc - 1].bankStat, (transacIndex + 1) * sizeof(Transection));
    validateAllocation(bankSystem[accountSelc - 1].bankStat);

    bankSystem[accountSelc - 1].bankStat[transacIndex].type = 1; 
    bankSystem[accountSelc - 1].bankStat[transacIndex].value = deposit;

    bankSystem[accountSelc - 1].num_transactions++;

    system("cls");

    printf("Deposit of R$ %.2f successfully!\n", deposit);
}

void makeWithdrawal()
{
    if(num_Accounts == 0)
    {
        printf("There is no accounts to make a withdrawal!!!\n");
        return;
    }

    int accountSelc;

    printf("Available accounts:\n\n");
    for(int i = 0; i < num_Accounts; i++)
    {
        printf("Account [%d]:\n", i + 1);
        printf("- Name: %s\n", bankSystem[i].name);
        printf("- Code: %s\n", bankSystem[i].codeAccount);
        printf("- Atual balance: %.2f\n\n", bankSystem[i].balance);
    }

    printf("Choose the account to which the withdrawal will be made:\n");
    scanf("%d", &accountSelc);
    
    while(!validateInterval(1, accountSelc, num_Accounts))
    {
        printf("Again!!!\n");
        scanf("%d", &accountSelc);
    }

    system("cls");
    
    float withdrawal;

    printf("How much money will be withdrawn?\n");
    scanf("%f", &withdrawal);

    while(!validateWithdrawal(bankSystem[accountSelc - 1].balance, withdrawal))
    {
        printf("You doesn't have enough money!!!\n");
        scanf("%f", &withdrawal);
    }

    bankSystem[accountSelc - 1].balance -= withdrawal;

    int transacIndex = bankSystem[accountSelc - 1].num_transactions;

    bankSystem[accountSelc - 1].bankStat = (Transection *)realloc(bankSystem[accountSelc - 1].bankStat, (transacIndex + 1) * sizeof(Transection));

    bankSystem[accountSelc - 1].bankStat[transacIndex].value = withdrawal;
    bankSystem[accountSelc - 1].bankStat[transacIndex].type = 2;

    bankSystem[accountSelc - 1].num_transactions++;

    system("cls");

    printf("Withdrawal of R$ %.2f successfully!!!\n", withdrawal);
}

void makeTransference()
{
    if(num_Accounts <= 1)
    {
        printf("There are not enough people!!!\n");
        return;
    }

    printf("Available accounts:\n\n");
    for(int i = 0; i < num_Accounts; i++)
    {
        printf("Account [%d]:\n", i + 1);
        printf("- Name: %s\n", bankSystem[i].name);
        printf("- Code: %s\n", bankSystem[i].codeAccount);
        printf("- Atual balance: %.2f\n\n", bankSystem[i].balance);
    }

    int whoSends;
    int whoReceives;

    printf("Who will send the money?\n");
    scanf("%d", &whoSends);

    system("cls");

    printf("Available accounts:\n\n");
    for(int i = 0; i < num_Accounts; i++)
    {
        if(i == (whoSends - 1)) continue;

        printf("Account [%d]:\n", i + 1);
        printf("- Name: %s\n", bankSystem[i].name);
        printf("- Code: %s\n", bankSystem[i].codeAccount);
        printf("- Atual balance: %.2f\n\n", bankSystem[i].balance);
    }

    printf("Who will receives the money?\n");
    scanf("%d", &whoReceives);

    while(whoReceives == whoSends)
    {
        printf("You must choose another account!!!\n");
        scanf("%d", &whoReceives);
    }

    system("cls");

    float valueSent;

    printf("How much money will be sent?\n");
    scanf("%f", &valueSent);

    while(!validateWithdrawal(bankSystem[whoSends - 1].balance, valueSent))
    {
        printf("%s doesn't have enough money for the transference!!!\n", bankSystem[whoSends - 1].name);
        scanf("%f", &valueSent);
    }

    int confirm;

    printf("Do you confirm a transference of R$ %.2f from %s to %s?\n", valueSent, bankSystem[whoSends - 1].name, bankSystem[whoReceives - 1].name);
    printf("(1) - yes, i do\n");
    printf("(2) - no, i don't\n");
    scanf("%d", &confirm);

    while(!validateConfirmation(confirm))
    {
        printf("Enter 1(yes) or 2(no)!!!\n");
        scanf("%d", &confirm);
    }

    if(confirm == 1)
    {
        system("cls");

        bankSystem[whoSends - 1].balance -= valueSent;
        bankSystem[whoReceives - 1].balance += valueSent;

        int transacIndex1 = bankSystem[whoSends - 1].num_transactions;
        int transacIndex2 = bankSystem[whoReceives - 1].num_transactions;

        bankSystem[whoSends - 1].bankStat = (Transection *)realloc(bankSystem[whoSends - 1].bankStat,(transacIndex1 + 1) * sizeof(Transection));
        bankSystem[whoReceives - 1].bankStat = (Transection *)realloc(bankSystem[whoReceives - 1].bankStat,(transacIndex2 + 1) * sizeof(Transection));

        bankSystem[whoSends - 1].bankStat[transacIndex1].value = valueSent;
        bankSystem[whoSends - 1].bankStat[transacIndex1].type = 3;
        bankSystem[whoSends - 1].bankStat[transacIndex1].flag = -1;
        
        bankSystem[whoSends - 1].bankStat[transacIndex1].whoReceived = (char *)malloc((strlen(bankSystem[whoReceives - 1].name) + 1) * sizeof(char));
        validateAllocation(bankSystem[whoSends - 1].bankStat[transacIndex1].whoReceived);
        strcpy(bankSystem[whoSends - 1].bankStat[transacIndex1].whoReceived, bankSystem[whoReceives - 1].name);

        bankSystem[whoReceives - 1].bankStat[transacIndex2].value = valueSent;
        bankSystem[whoReceives - 1].bankStat[transacIndex2].type = 3;
        bankSystem[whoReceives - 1].bankStat[transacIndex2].flag = 1;

        bankSystem[whoReceives - 1].bankStat[transacIndex2].whoSent = (char *)malloc((strlen(bankSystem[whoSends - 1].name) + 1) * sizeof(char));
        validateAllocation(bankSystem[whoReceives - 1].bankStat[transacIndex2].whoSent);
        strcpy(bankSystem[whoReceives - 1].bankStat[transacIndex2].whoSent, bankSystem[whoSends - 1].name);

        bankSystem[whoSends - 1].num_transactions++;
        bankSystem[whoReceives - 1].num_transactions++;

        printf("Transference of R$ %.2f from %s to %s sucessfully!!!\n", valueSent, bankSystem[whoSends - 1].name, bankSystem[whoReceives - 1].name);

        displayAllAccounts();
    } else {
        system("cls");
        printf("Transference canceled.\n");
    }
}

void bankStatOptions()
{
    printf("--  Bank Statement Options  --");
    printf("|---------------------------------|\n");
    printf("|(1) - Display All Accounts       |\n");
    printf("|(2) - Display One Account        |\n");
    printf("|---------------------------------|\n");
    printf("Enter the option:\n");
}

void viewBankStatement()
{
    if(num_Accounts == 0)
    {
        printf("There are no accounts to view!!!\n");
        return;
    }

    int bankStatOp;

    bankStatOptions();
    scanf("%d", &bankStatOp);

    switch(bankStatOp)
    {
        case 1:
            displayAllAccounts();
            break;
        case 2:
            // displayOneAccount();
            break;
        default:
            printf("Invalid option!!!\n");
            break;
    }
}

void displayAllAccounts()
{
    if(num_Accounts == 0)
    {
        printf("There are no accounts to display!!!\n");
        return;
    }

    printf("All available accounts:\n\n");
    for(int i = 0; i < num_Accounts; i++)
    {
        printf("Account [%d]:\n", i + 1);
        printf("- Name: %s\n", bankSystem[i].name);
        printf("- Code: %s\n", bankSystem[i].codeAccount);
        printf("- Current balance: %.2f\n\n", bankSystem[i].balance);

        printf("--      All Transections        --\n");
        printf("|---------------------------------|\n");
        
        if(bankSystem[i].num_transactions > 0)
        {
            for(int j = 0; j < bankSystem[i].num_transactions; j++)
            {
                if(bankSystem[i].bankStat[j].type == 1) {
                    printf("R$ %.2f was deposited into this account\n", bankSystem[i].bankStat[j].value);
                } else if(bankSystem[i].bankStat[j].type == 2) {
                    printf("R$ %.2f was withdrawn from this account\n", bankSystem[i].bankStat[j].value);
                } else if(bankSystem[i].bankStat[j].type == 3) {
                    if(bankSystem[i].bankStat[j].flag == 1) {
                        printf("This account received R$ %.2f from %s\n", bankSystem[i].bankStat[j].value, bankSystem[i].bankStat[j].whoSent);
                    } else if(bankSystem[i].bankStat[j].flag == -1) {
                        printf("This account trensferred R$ %.2f to %s\n", bankSystem[i].bankStat[j].value, bankSystem[i].bankStat[j].whoReceived);
                    }
                }
            }
        } else {
            printf("This account has not made any transactions yet");
            printf("|---------------------------------|\n");
        }
    }
}

void validateAllocation(void *ptr)
{
    if (ptr == NULL) 
    {
        printf("Error to memory allocation!!!\n");
        exit(1);  
    }
}

bool validateCode(char code[])
{
    bool state = true;
    char tam = strlen(code);

    if(tam != 16) state = false;
    
    for(int i = 0; code[i] != '\0'; i++)
    {
        if(!isdigit(code[i])) state = false;
    }

    return state;
}

bool validateAnyValue(float value)
{
    bool state = true;

    if(value < 0) state = false;

    return state;
}

bool validateInterval(int a, int x, int b)
{
    bool state = true;

    if(x < a || x > b) state = false;

    return state;
}

bool validateConfirmation(int c)
{
    bool state = true;

    if(c != 1 && c != 2) state = false;

    return state;
}

bool validateWithdrawal(float balnc, float withdrawal)
{
    bool state = true;

    if(balnc < withdrawal)
    {
        state = false;
    }

    return state;
}