#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Property Structure
struct property {
    char proID[100];
    int price;
    char city[100];
    char nh[100];
    char tpd[100];
    char at[100];
};

//Price Range Structure
struct capital{
// Price range
char pr[100];
// neighborhood
char nhp[100];
};

//Builders information structure
struct builders{
    //Builder ID
    char id[100];
    //Builder name
    char name[100];
    //builder contact
    char cn[100];
    //builder specialization
    char Spe[100];
    //builder city
    char city[100];
    //builder email id
    char eid[100];
    //builder years of experience
    char ye[100];
    //builders completed projects
    char cp[100];
    //builder Website
    char ws[100];
};

struct property details[25];
struct capital pri[25];
struct builders bui[25];


//property = pro
void displaypro(struct property details[],int count);
//Search by City
void citypro(struct property details[],int count,char city[]);
//Search by neighborhood
void bynd(struct property details[],int count,char nh[]);
//Filter by price
void byprice(struct property details[],int count,int mp);
//Fiter by Price Scope
void bytd(struct property details[],int count,char tpd[]);
//To display all Price ranges
void displayprice(struct capital pri[],int count);
//Search the Price Range by Neighborhood
void ndprice(struct capital pri[],int count,char nhp[]);
//Search in City of Neighborhood
void cynd(struct property details[],int count,char city[],char nh[]);
//Display all Builders Information
void displaybuilders(struct builders bui[],int count);


int main() {
    int pro = 0;
    int cap = 0;
    int build = 0;

    // Open the property file
    FILE *file = fopen("C:/DSA Pro/PRList.csv", "r");
    if (file == NULL) {
        printf("Error opening properties file for reading!\n");
        return 1;
    }

    char buffer[200];
    fgets(buffer, 200, file); // Skip the header line

    // Read properties data
    while (fgets(buffer, 200, file) != NULL && pro < 25) {
        sscanf(buffer, "%[^,],%d,%[^,],%[^,],%[^,],%[^,\n]",
               details[pro].proID,
               &details[pro].price,
               details[pro].city,
               details[pro].nh,
               details[pro].tpd,
               details[pro].at);
        pro++;
    }
    fclose(file);

    // Open the capital file
    FILE *fr = fopen("C:/DSA Pro/PRange.csv", "r");
    if (fr == NULL) {
        printf("Error opening capital file for reading!\n");
        return 1;
    }
    fgets(buffer, 200, fr); // Skip the header line

    // Read capital data
    while (fgets(buffer, 200, fr) != NULL && cap < 25) {
        sscanf(buffer, "%[^,],%[^,\n]",
               pri[cap].pr,
               pri[cap].nhp);

        cap++;
    }
    fclose(fr);

    // Open the builder file
    FILE *fb = fopen("C:/DSA Pro/PRbuild.csv", "r");
    if (fb == NULL) {
        printf("Error opening builders file for reading!\n");
        return 1;
    }
    fgets(buffer, 200, fb); // Skip the header line

    // Read builders data
    while (fgets(buffer, 200, fb) != NULL && build < 25) {
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]",
               bui[build].id,
               bui[build].name,
               bui[build].cn,
               bui[build].Spe,
               bui[build].city,
               bui[build].eid,
               bui[build].ye,
               bui[build].cp,
               bui[build].ws);
        build++;
    }
    fclose(fb);



    int upperchoice; //whole Switch
    int choice;  //for Property switch
    int buichoice; //for builder Choice
    int subchoice; // in City area

    printf("--------------------------------------------------\n");
    printf("1. Do you want to go in Builders\n");
    printf("2. Do you want to go in Properties\n");
    printf("---------------------------------------------------\n\n");

    printf("Enter your choice: ");
    scanf("%d",&upperchoice);

    switch(upperchoice) {
        case 1:
            printf("-----------------------------------------\n");
            printf("1. Do you want to See all Builder Details\n");
            printf("2. Do You want .......\n");
            printf("3. Exit\n");
            printf("-------------------------------------------\n\n");


            printf("Enter your Choice:");
            scanf("%d",&buichoice);

            switch (buichoice) {
                case 1:
                    printf("Builders Information\n\n");
                    displaybuilders(bui,build);
                    break;
                case 2:
                    break;
                case 3:
                    printf("Thank you\n");
                    exit(0);
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
            }break;

        case 2:


            printf("What would you like to do?\n");
            printf("---------------------------------------\n");
            printf("1. Display all Properties\n");
            printf("2. Search Property By Neighborhood\n");
            printf("3. Search Property By City\n");
            printf("4. Search Property By Price\n");
            printf("5. Search Property By Price Scope\n");
            printf("6. Display all Properties by Price Range\n");
            printf("7. Display all Price Range by Neighborhood\n");
            printf("8. Exit\n");
            printf("-------------------------------------------\n\n");

            printf("Enter you choice(1-8): ");
            scanf("%d",&choice);

            //Switich Statement
            switch(choice) {
                case 1:
                    printf("Data Property\n");
                    displaypro(details,pro);
                    break;
                case 2:
                    char nh[100];
                    printf("Enter the neighborhood you are looking for in UK:");
                    scanf("%s",nh);
                    bynd(details,pro,nh);
                    break;
                case 3:
                    char city[100];
                    printf("Enter the City you are looking for:");
                    scanf("%s",city);

                    printf("1. Do you want to See all properties in %s\n",city);
                    printf("2. Do you want to see specific Properties in %s\n",city);
                    printf("3. Exit\n");

                    printf("Enter your Choice further:");
                    scanf("%d",&subchoice);

                    switch (subchoice) {
                        case 1:
                            citypro(details,details,city);
                            break;
                        case 2:
                            char nh[100];
                            printf("Enter want neighborhood you looking for in %s:",city);
                            scanf("%s",nh);
                            cynd(details,pro,city,nh);
                            break;
                        case 3:
                            printf("Thank you \n");
                            exit(0);
                            break;
                        default:
                            printf("Invalid Choice\n");
                            break;
                    }
                    break;

                case 4:
                    int mp;
                    printf("Enter the Max Price in which you looking for:");
                    scanf("%d",&mp);
                    byprice(details,pro,mp);
                    break;
                case 5:
                    char tpd[100];
                    printf("Enter the Price Scope you are looking for:");
                    scanf("%s",tpd);
                    bytd(details,pro,tpd);
                    break;
                case 6:
                    printf("Price Range: \n");
                    displayprice(pri,cap);
                    break;
                case 7:
                    char nhp[100];
                    printf("Enter the neighborhood Price Range you are looking for:");
                    scanf("%s",nhp);
                    ndprice(pri,cap,nhp);
                    break;
                case 8:
                    printf("Thank you\nYour Dream Home is waiting for you\n");
                    exit(0);
                    break;
                default:
                    printf("Wrong choice\n");
                    break;


            }
    }

return 0;
};

void displaybuilders(struct builders bui[],int count) {
    printf("Builders Details\n\n");
    for(int i=0;i<count;i++) {
        printf("ID:%s\n",bui[i].id);
        printf("Name: %s\n",bui[i].name);
        printf("Contact no.: %s\n",bui[i].cn);
        printf("Specialization: %s\n",bui[i].Spe);
        printf("City: %s\n",bui[i].city);
        printf("Email Id: %s\n",bui[i].eid);
        printf("Years Of Experience: %s\n",bui[i].ye);
        printf("Completed Projects: %s\n",bui[i].cp);
        printf("Website: %s\n",bui[i].ws);
        printf("----------------------------\n\n\n");
    }
}


//Funtion to display all properties
void displaypro(struct property details[], int count) {
    printf("Property Details:\n\n");
    for (int i = 0; i < count; i++) {
        printf("Property ID: %s\n", details[i].proID);
        printf("Price: %d\n", details[i].price);
        printf("City: %s\n", details[i].city);
        printf("Neighborhood: %s\n", details[i].nh);
        printf("Total Properties: %s\n", details[i].tpd);
        printf("AT: %s\n", details[i].at);
        printf("---------------------------\n");
    }
}


//Funtion to Search By City
void citypro(struct property details[],int count, char city[]) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(details[i].city,city)!=NULL){
            printf("Property ID: %s\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Total Properties: %s\n", details[i].tpd);
            printf("AT: %s\n", details[i].at);
            printf("---------------------------\n");
            found = 1;
        }
    }
    if(!found) {
        printf("City not there\n");
    }
}

// Funtion to Search by neighborhood
void bynd(struct property details[], int count, char nh[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", nh);
    for (int i = 0; i < count; i++) {
        if (strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %s\n", details[i].proID);
            printf("Price: %s\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n", nh);
    }
}

void byprice(struct property details[],int count,int mp){
    int found = 0;
    printf("Property under %d:\n",mp);
    for (int i = 0; i < count; i++) {
        if (details[i].price) {
            printf("\nProperty ID: %s\n", details[i].proID);
            printf("Price: %s\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("----------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No Properties found under %d:\n",mp);
    }
}

void bytd(struct property details[],int count,char tpd[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", tpd);
    for (int i = 0; i < count; i++) {
        if (strstr(details[i].tpd, tpd) != NULL) {
            printf("\nProperty ID: %s\n", details[i].proID);
            printf("Price: %s\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n",tpd);
    }
}

void displayprice(struct capital pri[],int count){
printf("Range Details:\n\n");
for(int i=0;i<count;i++){
    printf("Price Range: %s\n",pri[i].pr);
    printf("Neighborhood: %s\n",pri[i].nhp);
    printf("-------------------------------------\n\n\n");
}
}

void ndprice(struct capital pri[],int count,char nhp[]){
    int found = 0;
    printf("The Price Range of %s is:\n", nhp);
    for (int i = 0; i < count; i++) {
        if (strstr(pri[i].nhp, nhp) != NULL) {
            printf("Neighborhood: %s\n", pri[i].nhp);
            printf("Price Range : %s\n", pri[i].pr);
            printf("---------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No neighborhood found near: %s\n", nhp);
    }
}

void cynd(struct property details[], int count, char city[], char nh[]) {
    int found = 0;
    printf("Searching for properties in %s near: %s\n", city, nh);

    for (int i = 0; i < count; i++) {
        int found = 0;
        // Check if the property matches the specified city and neighborhood
        if (strcmp(details[i].city, city) == 0 && strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %s\n", details[i].proID);
            printf("Price: %s\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No more properties found in %s near: %s\n", city, nh);
    }
}

//......................
