#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Property Structure
struct property {
    int proID;
    int price;
    char city[100];
    char nh[100];
    char tpd[100];
    char at[100];
    char aval[100];
};

//Price Range Structure
struct capital{
    // Price range from
    int ps;
    // Price range to
    int pe;
    // neighborhood
    char nhp[100];
};

//Builders information structure
struct builders{
    //Builder ID
    int id;
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

struct combined {
    struct property details[25];
    struct capital pri[25];
    struct builders bui[25];
};

struct combined con;

int id;

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
//Search specific Builders
void bybui(struct builders bui[],int count,char name[]);
//check Properties Availability
void byaval(struct property details[],int count,char aval[]);
//Print in neighborhood according to Price
void ndpr(struct property details[],char nh[100],int mp,int count);
//City to nh to price
void cyndpr(struct property details[],char nh[100],int mp,int count,char city[100]);
// Price to Price Range
void pripr(struct property details[],struct capital pri[],int count, int mp);
// Get properties details
void buy(struct property details[],struct builders bui[],struct capital pri[],int count,int id);


int main() {
    int pro = 0;
    int cap = 0;
    int build = 0;

    // Open the property file
    /* Change the full file loaction were you saved the file and then enter PRList.csv and
     change \ bracket to / this if you copy location   */
    FILE *file = fopen("C:/DSA Pro/PRList.csv", "r");
    if (file == NULL) {
        printf("Error opening properties file for reading!\n");
        return 1;
    }

    char buffer[200];
    fgets(buffer, 200, file); // Skip the header line

    // Read properties data
    while (fgets(buffer, 200, file) != NULL && pro < 25) {
        sscanf(buffer, "%d,%d,%[^,],%[^,],%[^,],%[^,],%[^\n,]",
               &con.details[pro].proID,
               &con.details[pro].price,
               con.details[pro].city,
               con.details[pro].nh,
               con.details[pro].tpd,
               con.details[pro].at,
               con.details[pro].aval);
        pro++;
    }
    fclose(file);

    // Open the capital file
    /* Change the full file loaction were you saved the file and then enter PRList.csv and
    change \ bracket to / this if you copy location   */
    FILE *fr = fopen("C:/DSA Pro/PRange.csv", "r");
    if (fr == NULL) {
        printf("Error opening capital file for reading!\n");
        return 1;
    }
    fgets(buffer, 200, fr); // Skip the header line

    // Read capital data
    while (fgets(buffer, 200, fr) != NULL && cap < 25) {
        sscanf(buffer, "%d,%d,%[^,\n]",
               &con.pri[cap].ps,
               &con.pri[cap].pe,
               con.pri[cap].nhp);

        cap++;
    }
    fclose(fr);

    // Open the builder file
    /* Change the full file loaction were you saved the file and then enter PRList.csv and
        change \ bracket to / this if you copy location   */
    FILE *fb = fopen("C:/DSA Pro/PRbuild.csv", "r");
    if (fb == NULL) {
        printf("Error opening builders file for reading!\n");
        return 1;
    }
    fgets(buffer, 200, fb); // Skip the header line

    // Read builders data
    while (fgets(buffer, 200, fb) != NULL && build < 25) {
        sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]",
               &con.bui[build].id,
               con.bui[build].name,
               con.bui[build].cn,
               con.bui[build].Spe,
               con.bui[build].city,
               con.bui[build].eid,
               con.bui[build].ye,
               con.bui[build].cp,
               con.bui[build].ws);
        build++;
    }
    fclose(fb);



    int upperchoice; //whole Switch
    int choice;  //for Property switch
    int buichoice; //for builder Choice
    int subchoice; // in City area
    int ndbyprice; //To nd as price via city
    int ndtoprice; //Direct ND to Price
    int pricetopr; // price to price range

    printf("--------------------------------------------------\n");
    printf("1. Do you want to go in Builders\n");
    printf("2. Do you want to go in Properties\n");
    printf("3. Do you want to go in Price Range \n");
    printf("4. Exit\n");
    printf("---------------------------------------------------\n\n");

    printf("Enter your choice: ");
    scanf("%d",&upperchoice);

    switch(upperchoice) {
        case 1:{
            printf("-----------------------------------------\n");
            printf("1. Do you want to See all Builder Details\n");
            printf("2. Do You want see Specific Builders Details\n");
            printf("3. Exit\n");
            printf("-------------------------------------------\n\n");


            printf("Enter your Choice:");
            scanf("%d",&buichoice);

            switch (buichoice) {
                case 1: {
                    printf("Builders Information\n\n");
                    displaybuilders(con.bui,build);
                    break;
                }
                case 2: {
                    char name[100];
                    printf("Enter the Builders you are looking for in UK:");
                    scanf("%s",name);
                    bybui(con.bui,build,name);
                    break;
                }
                case 3: {
                    printf("Thank you\n");
                    exit(0);
                }
                default: {
                    printf("Invalid Choice\n");
                    break;
                }
            }
        }break;

        case 2: {
            printf("What would you like to do?\n");
            printf("---------------------------------------\n");
            printf("1. Display all Properties\n");
            printf("2. Search Property By Neighborhood\n");
            printf("3. Search Property By City\n");
            printf("4. Search Property By Price\n");
            printf("5. Search Property By Price Scope\n");
            printf("6. Check Availability of properties\n");
            printf("7. Exit\n");
            printf("-------------------------------------------\n\n");

            printf("Enter you choice(1-7): ");
            scanf("%d",&choice);

            //Switich Statement
            switch(choice) {
                case 1:{
                    printf("Data Property\n");
                    displaypro(con.details,pro);

                    printf("Which Property you want to buy from the given details(Enter ID):");
                    scanf("%d",&id);
                    buy(con.details,con.bui,con.pri,pro,id);
                    break;
            }
                case 2: {
                    // NH Fun
                    char nh[100];
                    printf("Enter the neighborhood you are looking for in UK:");
                    scanf("%s",nh);


                    printf("1. Do you want to see all properties in %s\n",nh);
                    printf("2. Do you want to as per price in %s\n\n",nh);
                    printf("Enter your choice: ");
                    scanf("%d",&ndtoprice);

                    switch (ndtoprice) {
                        case 1: {
                            // All NH in UK
                            bynd(con.details,pro,nh);
                            printf("Which Property you want to buy from the given details(Enter ID):");
                            scanf("%d",&id);
                            buy(con.details,con.bui,con.pri,pro,id);
                            break;
                        }
                        case 2: {
                            // NH to Price
                            int mp;
                            printf("Enter the Max Price in which you looking for:");
                            scanf("%d",&mp);
                            ndpr(con.details,nh,mp,pro);

                            printf("Which Property you want to buy from the given details(Enter ID):");
                            scanf("%d",&id);
                            buy(con.details,con.bui,con.pri,pro,id);
                            break;
                        }
                        default: {
                            printf("Wrong Choice\n");
                            break;
                        }
                    }
                }
                    break;

                case 3: {
                    // City Fun Case study
                    char city[100];
                    printf("Enter the City you are looking for:");
                    scanf("%s",city);

                    printf("1. Do you want to See all properties in %s\n",city);
                    printf("2. Do you want to see specific Properties in %s\n",city);
                    printf("3. Exit\n\n");

                    printf("Enter your Choice further:");
                    scanf("%d",&subchoice);

                    switch (subchoice) {
                        case 1: // ALL City calling
                            citypro(con.details,pro,city);

                            printf("Which Property you want to buy from the given details(Enter ID):");
                            scanf("%d",&id);
                            buy(con.details,con.bui,con.pri,pro,id);
                            break;
                        case 2: {
                            // NH of Base of City
                            char nh[100];
                            printf("Enter want neighborhood you looking for in %s:",city);
                            scanf("%s",nh);

                            printf("1. Do you want to see all properties in %s\n",nh);
                            printf("2. Do you want to as per price in %s\n\n",nh);

                            printf("Enter your Choice further:");
                            scanf("%d",&ndbyprice);

                            switch (ndbyprice) {
                                case 1: {
                                    // city to nh inside
                                    cynd(con.details,pro,city,nh);
                                    printf("Which Property you want to buy from the given details(Enter ID):");
                                    scanf("%d",&id);
                                    buy(con.details,con.bui,con.pri,pro,id);
                                    break;
                                }
                                case 2: {
                                    // city to nh to price
                                    int mp;
                                    printf("Enter the Max Price in which you looking for:");
                                    scanf("%d",&mp);
                                    cyndpr(con.details,nh,mp,pro,city);
                                    printf("Which Property you want to buy from the given details(Enter ID):");
                                    scanf("%d",&id);
                                    buy(con.details,con.bui,con.pri,pro,id);
                                    break;
                                }
                                default: {
                                    printf("Wrong Choice\n");
                                    break;
                                }
                            }
                        }
                            break;
                        case 3: {
                            printf("Thank you \n");
                            exit(0);
                        }
                        default: {
                            printf("Invalid Choice\n");
                            break;
                        }
                    }
                }break;

                case 4: {
                    //Price Fun
                    int mp;
                    printf("Enter the Max Price in which you looking for:");
                    scanf("%d",&mp);

                    printf("------------------------------------------------------\n");
                    printf("1. Do you want to see Properties in price range\n");
                    printf("2. Do you want to as per price range\n\n");
                    printf("-----------------------------------------------------\n");

                    printf("Enter your Choice further:");
                    scanf("%d",&pricetopr);

                    switch (pricetopr) {
                        case 1: {
                            // All Price details
                            byprice(con.details,pro,mp);

                            printf("Which Property you want to buy from the given details(Enter ID):");
                            scanf("%d",&id);
                            buy(con.details,con.bui,con.pri,pro,id);
                            break;
                        }
                        case 2:{
                            pripr(con.details,con.pri,pro,mp);
                            printf("Which Property you want to buy from the given details(Enter ID):");
                            scanf("%d",&id);
                            buy(con.details,con.bui,con.pri,pro,id);
                            break;
                    }
                        default: {
                            printf("Wrong Choice\n");
                            break;
                        }
                    }
                }
                    break;
                case 5: {
                    // Price scope fun
                    char tpd[100];
                    printf("Enter the Price Scope you are looking for:");
                    scanf("%s",tpd);
                    bytd(con.details,pro,tpd);

                    printf("Which Property you want to buy from the given details(Enter ID):");
                    scanf("%d",&id);
                    buy(con.details,con.bui,con.pri,pro,id);
                    break;
                }
                case 6: {
                    // Aval check Fun
                    char aval[100];
                    printf("Enter the availability of Property you are looking for:");
                    scanf("%s",aval);
                    byaval(con.details,pro,aval);

                    printf("Which Property you want to buy from the given details(Enter ID):");
                    scanf("%d",&id);
                    buy(con.details,con.bui,con.pri,pro,id);
                    break;
                }
                case 7: {
                    // Exit
                    printf("Thank you\nYour Dream Home is waiting for you\n");
                    exit(0);
                }
                default: {
                    printf("Wrong choice\n");
                    break;
                }
            }
        }break;

        case 3:{

            printf("----------------------------------------------\n");
            printf("1. Display all Properties by Price Range\n");
            printf("2. Display all Price Range by Neighborhood\n");
            printf("3. Display all properties as between different range\n");
            printf("3. Exit\n");
            printf("----------------------------------------------\n");

            printf("Enter your Choice(1-4):");
            scanf("%d",&ndbyprice);


            switch (ndbyprice) {
                case 1: {
                    printf("Price Range: \n");
                    displayprice(con.pri,cap);
                    break;
                }
                case 2: {
                    char nhp[100];
                    printf("Enter the neighborhood Price Range you are looking for:");
                    scanf("%s",nhp);
                    ndprice(con.pri,cap,nhp);
                    break;
                }
                case 3: {
                    int mp;
                    printf("Enter the Max Price in which you looking for:");
                    scanf("%d",&mp);
                    pripr(con.details,con.pri,pro,mp);
                    break;
                }
                case 4: {
                    printf("Thank you \n");
                    exit(0);
                }
                default: {
                    printf("Wrong choice\n");
                    break;
                };
            }
    }break;
        case 4: {
            printf("Thank you, Visit Again\n");
            exit(0);
        }
        default: {
            printf("Wrong choice\n");
            break;
        }
    }

return 0;
};

void displaybuilders(struct builders bui[],int count) {
    printf("Builders Details\n\n");
    for(int i=0;i<count;i++) {
        printf("ID:%d\n",bui[i].id);
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


//Fun to display all properties
void displaypro(struct property details[], int count) {
    printf("Property Details:\n\n");
    for (int i = 0; i < count; i++) {
        printf("Property ID: %d\n", details[i].proID);
        printf("Price: %d\n", details[i].price);
        printf("City: %s\n", details[i].city);
        printf("Neighborhood: %s\n", details[i].nh);
        printf("Total Properties: %s\n", details[i].tpd);
        printf("AT: %s\n", details[i].at);
        printf("Availability: %s\n",details[i].aval);
        printf("---------------------------\n");
    }
}


//Fun to Search By City
void citypro(struct property details[],int count, char city[]) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(details[i].city,city)!=NULL){
            printf("Property ID: %d\n", details[i].proID);
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
        printf("City not there\n\n");
    }
}

// Fun to Search by neighborhood
void bynd(struct property details[], int count, char nh[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", nh);
    for (int i = 0; i < count; i++) {
        if (strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n\n", nh);
    }
}

//Fun to Sort by City
void byprice(struct property details[],int count,int mp){
    int found = 0;
    printf("Property under %d:\n",mp);
    for (int i = 0; i < count; i++) {
        if (details[i].price <= mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("----------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No Properties found under %d:\n\n",mp);
    }
}

//Fun to Search By Price Scope
void bytd(struct property details[],int count,char tpd[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", tpd);
    for (int i = 0; i < count; i++) {
        if (strstr(details[i].tpd, tpd) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n\n",tpd);
    }
}

//Fun to Display Price range
void displayprice(struct capital pri[],int count){
printf("Range Details:\n\n");
for(int i=0;i<count;i++){
    printf("Price Range From: %d\n",pri[i].ps);
    printf("Price Range To: %d\n",pri[i].pe);
    printf("Neighborhood: %s\n",pri[i].nhp);
    printf("-------------------------------------\n\n\n");
}
}

//Fun to Search the price range by neighborhood
void ndprice(struct capital pri[],int count,char nhp[]){
    int found = 0;
    printf("The Price Range of %s is:\n", nhp);
    for (int i = 0; i < count; i++) {
        if (strstr(pri[i].nhp, nhp) != NULL) {
            printf("Neighborhood: %s\n", pri[i].nhp);
            printf("Price Range From: %d\n", pri[i].ps);
            printf("Price Range to: %d\n",pri[i].pe);
            printf("---------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No neighborhood found near: %s\n\n", nhp);
    }
}

//Fun to Search in city to nh
void cynd(struct property details[], int count, char city[], char nh[]) {
    const int found= 0;
    printf("Searching for properties in %s near: %s\n", city, nh);

    for (int i = 0; i < count; i++) {
        // Check if the property matches the specified city and neighborhood
        if (strcmp(details[i].city, city) == 0 && strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
        }
    }

    if (!found) {
        printf("No more properties found\n\n");
    }
}

//Fun to Search by builders name
void bybui(struct builders bui[],int count,char name[]) {
    int found = 0;
    printf("Searching for Builder: %s\n", name);
    for (int i = 0; i < count; i++) {
        if (strstr(bui[i].name, name) != NULL) {
            printf("ID:%d\n",bui[i].id);
            printf("Name: %s\n",bui[i].name);
            printf("Contact no.: %s\n",bui[i].cn);
            printf("Specialization: %s\n",bui[i].Spe);
            printf("City: %s\n",bui[i].city);
            printf("Email Id: %s\n",bui[i].eid);
            printf("Years Of Experience: %s\n",bui[i].ye);
            printf("Completed Projects: %s\n",bui[i].cp);
            printf("Website: %s\n",bui[i].ws);
            printf("----------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No Builder found : %s\n\n",name);
    }
}

//Fun to Check aval of property
void byaval(struct property details[],int count, char aval[]) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(details[i].aval,aval)!=NULL){
            printf("Property ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Total Properties: %s\n", details[i].tpd);
            printf("AT: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("---------------------------\n");
            found = 1;
        }
    }
    if(!found) {
        printf("Property input not valid\n\n");
    }
}

//Fun to Search in nh to price
void ndpr(struct property details[],char nh[100],int mp,int count) {
    int found = 0;
    printf("Searching for properties in %s in: %d\n", nh, mp);

    for (int i = 0; i < count; i++) {
        // Check if the property matches the specified neighborhood and price
        if (strstr(details[i].nh, nh) != NULL && details[i].price <= mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No more properties found in %s under: %d\n\n", nh, mp);
    }
}

//Fun to Search in city to nh to price
void cyndpr(struct property details[],char nh[100],int mp,int count,char city[100]) {
    int found = 0;
    printf("Searching for properties in %s in: %d\n", nh, mp);

    for (int i = 0; i < count; i++) {
        // Check if the property matches the specified neighborhood and price
        if (strcmp(details[i].city, city) == 0 && strstr(details[i].nh, nh) != NULL && details[i].price <= mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No more properties found in %s under: %d\n\n", nh, mp);
    }
}

//Fun from Price to Price range
void pripr(struct property details[],struct capital pri[],int count, int mp) {
    int found = 0;
    printf("Searching for properties in: %d\n", mp);

    for (int i = 0; i < count; i++) {
        // Check if the property matches the specified neighborhood and price
        if (details[i].price <=mp && pri[i].ps <= mp && pri[i].pe >= mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");

            printf("Price Range Details:\n\n");
            printf("Price Range From: %d\n",pri[i].ps);
            printf("Price Range To: %d\n",pri[i].pe);
            printf("Neighborhood: %s\n",pri[i].nhp);
            printf("-------------------------------------\n\n\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No more properties found in %d\n\n",mp);
    }
}

void buy(struct property details[],struct builders bui[],struct capital pri[],int count,int id) {
    int found = 0;
    printf("Searching for Builder:\n");
    for (int i = 0; i < count; i++) {
        if (id==bui[i].id) {
            printf("Builder Information of Selected Property: \n");
            printf("---------------------------\n");
            printf("ID:%d\n",bui[i].id);
            printf("Name: %s\n",bui[i].name);
            printf("Contact no.: %s\n",bui[i].cn);
            printf("Specialization: %s\n",bui[i].Spe);
            printf("City: %s\n",bui[i].city);
            printf("Email Id: %s\n",bui[i].eid);
            printf("Years Of Experience: %s\n",bui[i].ye);
            printf("Completed Projects: %s\n",bui[i].cp);
            printf("Website: %s\n",bui[i].ws);
            printf("----------------------------\n\n\n");
            found = 1;

            printf("Property Information you want:\n");
            printf("----------------------------------------\n");
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("Availability: %s\n",details[i].aval);
            printf("------------------------------------\n\n\n");
        }
    }
    if (!found) {
        printf("No Builders or Property found at id %d\n\n",id);
    }
}

//.........................................
