#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define area 25
#define money 10
#define build 25

typedef struct {
    //property ID = proid
    int proID;
    //Price
    int price;
    //City in which it is
    char city[100];
    // neighborhood = nh
    char nh[100];
    //pricing detail = tpd
    char tpd[100];
    //AuthenticationType = at
    char at[100];
}property;

typedef struct {
// Price range start
int ps;
//price range end
int pe;
char nhp[100];
}capital;

typedef struct {
    //Builder ID
    int id;
    //Builder name
    char name[100];
    //builder contact
    char cn[100];
    //builders specialization
    char Spe[100];
    //builder city
    char city[100];
    //builder email id
    char eid[100];
    //builder years of experience
    int ye;
    //builders completed projects
    int cp;
    //builder Website
    char ws[100];
}builders;

//property = pro
void displaypro(property details[],int count);
//Search by City
void citypro(property details[],int count,char city[]);
//Search by neighborhood
void bynd(property details[],int n,char nh[]);
//Filter by price
void byprice(property details[],int count,int mp);
//Fiter by Price Scope
void bytd(property details[],int count,char tpd[]);
//To display all Price ranges
void displayprice(capital pri[],int pr);
//Search the Price Range by Neighborhood
void ndprice(capital pri[],int prn,char nhp[]);
//Search in City of Neighborhood
void cynd(property details[],int n,char city[],char nh[]);
//Display all Builders Information
void displaybuilders(builders bui[],int count);

int main() {
    // All Data
    property details[area]={
        {101,7500000,"Dehradun","Near City Center, Schools, Parks","Verified by Govt. Registry","OTP-based login"},
        {102,12000000,"Rishikesh","Riverside, Hospitals, Malls","No hidden charges","Biometric login"},
        {103,9500000,"Almora","Suburban, Green Spaces, Markets","Tax-inclusive pricing","Email verification"},
        {104,6000000,"Haridwar","Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {105,25000000,"Mussoorie","Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {106,8500000,"Haridwar","Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {107,17500000,"Mussoorie","Hill Station, Resorts, Trails","No hidden fees","Face recognition"},
        {108,5000000,"Pauri Garhwal","Rural, Farms, Local Markets","Transparent pricing","OTP-based login"},
        {109,10000000,"Dehradun","Urban, IT Parks, Shopping Centers","Verified by Govt. Registry","Biometric login"},
        {110,15000000,"Haridwar","Riverside, Restaurants, Hotels","Tax-inclusive pricing","Email verification"},
        {111,7000000,"Mussoorie","Near Forest, Schools, Hospitals","Transparent breakdown","Mobile number verification"},
        {112,20000000,"Dehradun","Premium Area, Clubs, High-end Shops","Clear contract terms","Two-factor authentication"},
        {113,9000000,"Mussoorie","Near Forest, Trails, Resorts","Govt. certified rates","Password-protected login"},
        {114,12500000,"Haridwar","Near River, Parks, Schools","No hidden fees","Face recognition"},
        {115,5500000,"Bageshwar","Suburban, Green Spaces, Markets","Transparent pricing","OTP-based login"},
        {116,11000000,"Rishikesh","River Area, Hospitals, Malls","Verified by Govt. Registry","Biometric login"},
        {117,8000000,"Dehradun","Near City Center, Schools, Parks","Tax-inclusive pricing","Email verification"},
        {118,6500000,"Haridwar","Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {119,27500000,"Dehradun","Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {120,14000000,"Rishikesh","Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {121,18000000,"Dehradun","Mall, Forest","Govt. certified rates","Password-protected login"},
        {122,34000000,"Haridwar","Riverside","Govt. certified rates","Password-protected login"},
        {123, 25000000, "Rishikesh","River, Retreat", "Private Limited Rates", "Two-Factor Authentication"},
        {124, 20000000, "Mussoorie","Hill, Tourism", "Seasonal Offers", "Biometric Access"},
        {125, 22000000, "Haridwar","Temple, Pilgrimage", "Govt. Subsidized Packages", "Encrypted Login System"}
    };

    // Data of area rate
    capital pri[money]={
        {7500000,8000000,"Near city center, schools, parks"},
        {11000000,12000000,"Coastal areas, hospitals, malls"},
        {5500000,9500000,"Suburban green spaces, markets"},
        {6000000,6500000,"Industrial zones, transport hubs"},
        {25000000,27500000,"Luxury areas, golf courses, clubs"},
        {8500000,14000000,"Riverside schools, local shops"},
        {17500000,20000000,"Hill stations, resorts, trails"},
        {5000000,7000000,"Rural farms, local markets"},
        {20000000,40000000,"Premium areas, clubs, high-end shops"},
        {15000000,20000000,"Beachfront, restaurants, hotels"},
        };

    //Data of Builders
    builders bui[build]={
        {101,"Horizon Builders","9876543210","Luxury apartments","Haridwar","horizon.builders@gmail.com",15,50,"www.horizonbuilders.com"},
        {102,"Skyline ventures","8765432198","Commercial Spaces","Dehradun","skyline.ventures@microsoft.com",10,35,"www.skyline.com"},
        {103,"Green Screen Creations","2988776655","Eco-Friendly","Roorkee","pinnacle.developers@gmail.com",8,25,"www.greenscapecreateions.com"},
        {104,"Pinnacle Developer","7788994400","High rise Buildings","Baghewar","pinnacle.developers@reddifmail.com",12,40,"www.pineappledevelopers.com"},
        {105,"DreamLand Constructions","7788994400","Budget Friendly homes","Rishikesh","dreamland.constructions@gmail.com",11,45,"www.urbanvistabuilders.com"},
        {106,"UrbanVista Builders","6677889900","Mixed-Use Developments","Haridwar","urbanvista.builders@gmail.com",11,45,"www.urbanvistabuilders.com"},
        {107,"Elite Contractors","2233445566","Villas and Bungalows","Mussoorie","elite.contractors@gmail.com",13,50,"www.elitecontractors"},
        {108,"Apex Architects","3344556699","IT Parks","Dehradun","apex.archietects@gmail.com",9,28,"www.apexarchitects.com"},
        {109,"Summit Constructors","3344556655","Retail Properties","Rishikesh","summit.constructions@gmail.com",13,40,"www.sumitconstruction.com"},
        {110,"Paradise Homes","2233445566","Retiement Homes","Haridwar","paradise.homes@gmail.com",6,20,"www.paradisehomes.com"},
        {111,"Vertex Builders","2233445566","Affordable Housing","Roorkee","vertex.builders@gmail.com",10,32,"www.vertexbuilders.com"},
        {112,"Nova Infrastucture","7788668866","Greenfield Projects","Mussoorie","nova.infastructue",9,26,"www.novainfrastructues.com"},
        {113,"Emerald Estates","8899664433","Gated Communties","Dehradun","emararld.estates@gmail.com",8,24,"www.emeralesatetes.com"},
        {114,"Zenith Constructions","9099887766","Industrial Estates","Haridwar","zenith.constructions@gmail.com",12,38,"www.zenithconstructions.com"},
        {115,"Cosmo Builders","8080665555","Smart Cites","Dehradun","cosmo.builders@gmailcom",14,45,"www.cosmobuilders.com"},
        {116,"Heritage Builders","7077555444","Heritage Restorations","Haridwar","heritage.builders@gmail.com",7,22,"www.heritagebuilders.com"},
        {117,"Visionary Homes","6066644333","Sustainable Houses","Rishikesh","visionary.homes@gmail.com",7,22,"www.visonaryhomes.com"},
        {118,"BluePeak Builders","5055333222","Tourist Resorts","Haridwar","bluepeak.builders@gmail.com",11,37,"www.bluepeakbuilders.com"},
        {119,"Starlight Projects","4044223321","Residental Towers","Dehradun","starlight.projects@gmail.com",6,19,"www.starlightprojects.com"},
        {120,"Pioneer Consturcutions","303332134","Hotels","Rishikesh","pioneer.constructions@gmail.com",15,49,"www.pioneerconstructions.com"},
        {121,"Coral Builders","1911323113","Riverside Properties","Haridwar","coralbuilders@gmail.com",14,40,"www.coralbuilers.com"},
        {122,"Vasturai Estates","202211133","Relegions Places","Haridwar","vasturi.esatates@gmail.com",10,33,"www.vasturiestates"},
        {123,"Dynamic Builders","181232123","Commercial pLaces","Dehradun","dynamic.builders@gmail.com",8,23,"www.dynamicbuilders.com"},
        {124,"Rising Builders","1711111231","Luxury Clubs","Mussoorie","rising.ventures@gail.com",13,35,"www.risingventures.com"},
        {125,"Harmony Builders","1611100112","Family Homes","Pauri Garwal","harmony.builders@gmail.com",10,30,"www.harmonybuilders.com"}
    };

    int upperchoice;
    int choice;
    int buichoice;
    int subchoice;

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
                    int count = build;
                    printf("Builders Information\n\n");
                    displaybuilders(bui,count);
                    break;
                case 2:
                    break;
                    case 3:
                    printf("Thank you\n");
                    exit(0);
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
                    int count = area;
                    printf("Data Property\n");
                    displaypro(details,count);
                    break;
                case 2:
                    int y = area;
                    char nh[100];
                    printf("Enter the neighborhood you are looking for in UK:");
                    scanf("%s",nh);
                    bynd(details,y,nh);
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
                            citypro(details,area,city);
                            break;
                        case 2:
                            char nh[100];
                            printf("Enter want neighborhood you looking for in %s:",city);
                            scanf("%s",nh);
                            cynd(details,area,city,nh);
                            break;
                            case 3:
                            printf("Thank you \n");
                            exit(0);
                            break;
                    }
                    break;

                case 4:
                    int mp;
                    printf("Enter the Max Price in which you looking for:");
                    scanf("%d",&mp);
                    byprice(details,area,mp);
                    break;
                case 5:
                    char tpd[100];
                    printf("Enter the Price Scope you are looking for:");
                    scanf("%s",tpd);
                    bytd(details,area,tpd);
                    break;
                case 6:
                    int pr = money;
                    printf("Price Range\n");
                    displayprice(pri,pr);
                    break;
                case 7:
                    int prn = money;
                    char nhp[100];
                    printf("Enter the neighborhood Price Range you are looking for:");
                    scanf("%s",nhp);
                    ndprice(pri,prn,nhp);
                    break;
                case 8:
                    printf("Thank you\nYour Dream Home is waiting for you\n");
                    exit(0);
                    break;
                default:
                    printf("Wrong choice\n");
                    break;

                    break;
            }
    }

return 0;
}

void displaybuilders(builders bui[],int count) {
    printf("Builders Details\n\n");
    for(int i=0;i<count;i++) {
        printf("ID:%d\n",bui[i].id);
        printf("Name: %s\n",bui[i].name);
        printf("Contact no.: %s\n",bui[i].cn);
        printf("Specialization: %s\n",bui[i].Spe);
        printf("City: %s\n",bui[i].city);
        printf("Email Id: %s\n",bui[i].eid);
        printf("Years Of Experience: %d\n",bui[i].ye);
        printf("Completed Projects: %d\n",bui[i].cp);
        printf("Website: %s\n",bui[i].ws);
        printf("----------------------------\n\n\n");
    }
}


//Funtion to display all properties
void displaypro(property details[],int count) {
    printf("Property Details\n\n\n");
    for(int i=0;i<count;i++) {
        printf("\nProperty ID: %d\n", details[i].proID);
        printf("Price: %d\n", details[i].price);
        printf("City: %s\n", details[i].city);
        printf("Neighborhood: %s\n", details[i].nh);
        printf("Pricing Details: %s\n", details[i].tpd);
        printf("Authentication Type: %s\n", details[i].at);
        printf("------------------------------------\n\n\n");
    }
}

//Funtion to Search By City
void citypro(property details[],int count, char city[]) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(details[i].city,city)!=NULL){
            printf("Property ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("-------------------------------------\n\n\n");
            found = 1;
        }
    }
    if(!found) {
        printf("City not there\n");
    }
}

// Funtion to Search by neighborhood
void bynd(property details[], int count, char nh[]) {
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
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n", nh);
    }
}

void byprice(property details[],int count,int mp){
    int found = 0;
    printf("Property under %d:\n",mp);
    for (int i = 0; i < count; i++) {
        if (details[i].price < mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
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

void bytd(property details[],int count,char tpd[]) {
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
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n",tpd);
    }
}

void displayprice(capital pri[],int pr){
printf("Range Details\n");
for(int i=0;i<pr;i++){
    printf("Price Range Start: %d\n",pri[i].ps);
    printf("Price Range End:  %d\n",pri[i].pe);
    printf("-------------------------------------\n\n\n");
}
}

void ndprice(capital pri[],int prn,char nhp[]){
    int found = 0;
    printf("The Price Range of %s is:\n", nhp);
    for (int i = 0; i < prn; i++) {
        if (strstr(pri[i].nhp, nhp) != NULL) {
            printf("Neighborhood: %s\n", pri[i].nhp);
            printf("Price Range Start: %d\n", pri[i].ps);
            printf("Price Range End: %d\n", pri[i].pe);
            printf("---------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No neighborhood found near: %s\n", nhp);
    }
}

void cynd(property details[], int count, char city[], char nh[]) {
    int found = 0;
    printf("Searching for properties in %s near: %s\n", city, nh);

    for (int i = 0; i < count; i++) {
        int found = 0;
        // Check if the property matches the specified city and neighborhood
        if (strcmp(details[i].city, city) == 0 && strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
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
