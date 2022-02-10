#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Prototypes
//function for printing out the starts
void playerStats(char class[50], int health, int armor, int strength, int magic, int speed, int luck, int mana);
//main
int main(int argc, char const *argv[]) {
  //VARIABLES
  int flag = 0;
  int flag1 = 0;
  int currRoom = 0;
  int room1Found = 0;
  int room2Found = 0;
  int room3Found = 0;
  int room4Found = 0;
  int room5Found = 0;
  int room6Found = 0;
  int room7Found = 0;
  int room8Found = 0;
  int room9Found = 0;
  int room10Found = 0;
  //vars for player input
  char class[50];
  char confirm[10];
  char input[50];
  char infoInput[50];
  char itemToEquip[50];
  char itemToDequip[50];
  char itemDequipDrop[50];
  char itemToDrop[50];
  //player-related vars
  int open = 7;
  char equipmentNames[7][50];
  int head = 0;
  int body = 0;
  int accessory = 0;
  int legs = 0;
  int feet = 0;
  int rHand = 0;
  int lHand = 0;
  //player position
  int x = 0;
  int y = 0;
  int z = 0;
  //const VARIABLES
  const char *classes[3];
  classes[0] = "Warrior";
  classes[1] = "Ranger";
  classes[2] = "Mage";

  const char *commands[19];
  commands[0] = "Help";
  commands[1] = "Exit";
  commands[2] = "Info";
  commands[3] = "Equipment";
  commands[4] = "Bag";
  commands[5] = "Equip";
  commands[6] = "Dequip";
  commands[7] = "Drop";
  commands[8] = "Use";
  commands[9] = "Cast";
  commands[10] = "Attack";
  commands[11] = "Search";
  commands[12] = "Forward";
  commands[13] = "Backward";
  commands[14] = "Right";
  commands[15] = "Left";
  commands[16] = "Up";
  commands[17] = "Down";
  commands[18] = "Spellbook";
  //flag VARIABLES
  int gameOver;
  int combat;
  int classChosen = 0;
  //Structure VARIABLES
  //struct var for enemies
  struct Monster{
    char name[50];
    int health;
    int strength;
    int speed;
    int gold;
    int experience;
  };
  //struct var for items
  int equipmentStrength;
  int equipmentHealth;
  int equipmentArmor;
  int equipmentSpeed;
  int equipmentMagic;
  int equipmentLuck;

  struct Item{
    char name[50];
    int strength;
    int health;
    int armor;
    int speed;
    int magic;
    int luck;
    int position;
  };
  //game items
struct Item none;
strcpy(none.name, "None");
none.strength = 0;
none.health = 0;
none.armor = 0;
none.speed = 0;
none.magic = 0;
none.luck = 0;
none.position = 10;

  struct Item ironHelm;
  strcpy(ironHelm.name, "Iron_Helm");
  ironHelm.strength = 0;
  ironHelm.health = 1;
  ironHelm.armor = 4;
  ironHelm.speed = 0;
  ironHelm.magic = 0;
  ironHelm.luck = 0;
  ironHelm.position = 0;

  struct Item wornClub;
  strcpy(wornClub.name, "Worn_Club");
  wornClub.strength = 4;
  wornClub.health = 0;
  wornClub.armor = 1;
  wornClub.speed = 0;
  wornClub.magic = 0;
  wornClub.luck = 0;
  wornClub.position = 5;

  struct Item woolCloak;
  strcpy(woolCloak.name, "Wool_Cloak");
  woolCloak.strength = 0;
  woolCloak.health = 1;
  woolCloak.armor = 2;
  woolCloak.speed = 3;
  woolCloak.magic = 0;
  woolCloak.luck = 0;
  woolCloak.position = 1;

  struct Item rustedDagger;
  strcpy(rustedDagger.name, "Rusted_Dagger");
  rustedDagger.strength = 3;
  rustedDagger.health = 0;
  rustedDagger.armor = 0;
  rustedDagger.speed = 1;
  rustedDagger.magic = 0;
  rustedDagger.luck = 0;
  rustedDagger.position = 5;

  struct Item ancientAmulet;
  strcpy(ancientAmulet.name, "Ancient_Amulet");
  ancientAmulet.strength = 0;
  ancientAmulet.health = 2;
  ancientAmulet.armor = 0;
  ancientAmulet.speed = 0;
  ancientAmulet.magic = 3;
  ancientAmulet.luck = 1;
  ancientAmulet.position = 2;

  struct Item basicWand;
  strcpy(basicWand.name, "Basic_Wand");
  basicWand.strength = 1;
  basicWand.health = 0;
  basicWand.armor = 0;
  basicWand.speed = 0;
  basicWand.magic = 3;
  basicWand.luck = 0;
  basicWand.position = 5;

  struct Item equipment[7];
  for (int i = 0; i < 7; i++){
    equipment[i] = none;
  }
  for (int i = 0; i < 7; i++){
    equipmentHealth += equipment[i].health;
    equipmentArmor += equipment[i].armor;
    equipmentStrength += equipment[i].strength;
    equipmentMagic += equipment[i].magic;
    equipmentSpeed += equipment[i].speed;
    equipmentLuck += equipment[i].luck;
  }

  struct Item bag[10];
  for (int i = 0; i < 10; i++){
    bag[i] = none;
  }

  struct Item room[50];
  for (int i = 0; i < 50; i++){
    room[i] = none;
  }
  //struct var for class
  struct Player{
    char class[50];
    int strength;
    int health;
    int armor;
    int speed;
    int magic;
    int luck;
    int mana;
  };

  //intialize the player
  struct Player player;

  //struct var for room
  struct Room{
    char name[50];
    int x;
    int y;
  };
  //struct var for spells
  struct Spell{
    char name[50];
    char effect[50];
    int amount;
    int duration;
    int mana;
  };
  //intialize filler spell
  struct Spell spell;
  strcpy(spell.name, "None");
  strcpy(spell.effect, "None");
  spell.amount = 0;
  spell.duration = 0;


  struct Spell rage;
  strcpy(rage.name, "Rage");
  strcpy(rage.effect, "Strength");
  rage.amount = 5;
  rage.duration = 2;

  struct Spell ironWill;
  strcpy(ironWill.name, "Iron_Will");
  strcpy(ironWill.effect, "Armor");
  ironWill.amount = 5;
  ironWill.duration = 3;
  //initialize spell book
  struct Spell spellbook[10];
  for (int i = 0; i < 10; i++){
    spellbook[i] = spell;
  }
  //initialize world
  struct Room world[10];
  //game
  printf("Welcome to the RPG! Choose your class!\n");
  for (int i = 0; i < 3; i++){
    printf("%s\n", classes[i]);
  }
  printf("\n");
  while (1){
    scanf("%s", class);
    if (strcmp(class, "Warrior") == 0 || strcmp(class, "warrior") == 0){
      printf("The warrior class is mainly focused on brute force and tenacity. Where the warrior lacks in speed and magic, they make up\n");
      printf("in their health pool and armor. The warrior starts with an iron helm and a worn club.\n");
      printf("\n");
      printf("Type \'Yes\' if you would like to choose this class.\n");
      printf("Type \'No\' if you would like to choose another class.\n");
      scanf("%s", confirm);
      if (strcmp(confirm, "Yes") == 0 || strcmp(confirm, "yes") == 0){
        equipment[0] = ironHelm;
        equipment[5] = wornClub;
        strcpy(player.class, "Warrior");
        player.strength = 5;
        player.health = 20;
        player.armor = 6;
        player.speed = 4;
        player.magic = 2;
        player.luck = 4;
        player.mana = 8;
        printf("You have chosen the %s class!\n", player.class);
        classChosen = 1;
        break;
      }
      else {
        classChosen = 0;
        continue;
      }
    }
    else if (strcmp(class, "Ranger") == 0 || strcmp(class, "ranger") == 0){
      printf("The ranger is mainly focused on agility and outsmarting their opponent. Where the ranger lacks in health and armor, they\n");
      printf("make up in their speed and luck. The ranger starts with a wool cloak and a rusted dagger.\n");
      printf("\n");
      printf("Type \'Yes\' if you would like to choose this class.\n");
      printf("Type \'No\' if you would like to choose another class.\n");
      scanf("%s", confirm);
      if (strcmp(confirm, "Yes") == 0 || strcmp(confirm, "yes") == 0){
        equipment[1] = woolCloak;
        equipment[5] = rustedDagger;
        strcpy(player.class, "Ranger");
        player.strength = 8;
        player.health = 10;
        player.armor = 2;
        player.speed = 10;
        player.magic = 4;
        player.luck = 8;
        player.mana = 10;
        printf("You have chosen the %s class!\n", player.class);
        classChosen = 1;
        break;
      }
      else {
        classChosen = 0;
        continue;
      }
    }
    else if (strcmp(class, "Mage") == 0 || strcmp(class, "mage") == 0){
      printf("The mage is mainly focused on casting spells and outsmarting your opponent. Where the mage lacks in speed and strength,\n");
      printf("they make up entirely in their magic. The mage starts with an ancient amulet and basic wand.\n");
      printf("\n");
      printf("Type \'Yes\' if you would like to choose this class.\n");
      printf("Type \'No\' if you would like to choose another class.\n");
      scanf("%s", confirm);
      if (strcmp(confirm, "Yes") == 0 || strcmp(confirm, "yes") == 0){
        equipment[2] = ancientAmulet;
        equipment[5] = basicWand;
        strcpy(player.class, "Mage");
        player.strength = 3;
        player.health = 15;
        player.armor = 3;
        player.speed = 5;
        player.magic = 10;
        player.luck = 6;
        player.mana = 15;
        printf("You have chosen the %s class!\n", player.class);
        classChosen = 1;
        break;
      }
      else {
        classChosen = 0;
        continue;
      }
    }
    else {
      printf("That is not a valid selection.\n");
      continue;
    }
  }
  if (classChosen = 1){
    //print intro text
    printf("Welcome traveler, you have come far. Your journey begins here, at the gates of a perilous dungeon. You have been sent\n");
    printf("by your king to find and snuff the source of darkness that has been unleashed onto the kingdom. It is also rumored that\n");
    printf("great rewards lie ahead amidst the inevitable dangers. The only way is forward, into the dungeon.\n");
    printf("\n");
    printf("Type \'Help\' to see list of commands\n");
    printf("\n");
    //start game loop
    while(1){
      //update the player based on items
      if (strcmp(equipment[0].name, "None") != 0){
        head = 1;
      }
      else {
        head = 0;
      }
      if (strcmp(equipment[1].name, "None") != 0){
        body = 1;
      }
      else {
        body = 0;
      }
      if (strcmp(equipment[2].name, "None") != 0){
        accessory = 1;
      }
      else {
        accessory = 0;
      }
      if (strcmp(equipment[3].name, "None") != 0){
        legs = 1;
      }
      else {
        legs = 0;
      }
      if (strcmp(equipment[4].name, "None") != 0){
        feet = 1;
      }
      else {
        feet = 0;
      }
      if (strcmp(equipment[5].name, "None") != 0){
        rHand = 1;
      }
      else {
        rHand = 0;
      }
      if (strcmp(equipment[6].name, "None") != 0){
        lHand = 1;
      }
      else {
        lHand = 0;
      }

      for (int i = 0; i < 7; i++){
        if (strcmp(equipment[i].name, "None")){
          open++;
        }
        else {
          open--;
        }
      }
      //establish currRoom value
      if (x == 0 && y == 0 && z == 0){
        currRoom = 0;
      }
      else if (x == 0 && y == 1 && z == 0){
        currRoom = 1;
      }
      //print out the room descriptions
      if (currRoom == 0){
        printf("Exits: Forward\n");
        printf("\n");
        flag1 = 0;
      }
      else if (currRoom == 1){
        if (flag1 != 1 && room2Found == 0){
          printf("You have entered the dungeon. Down the dark hallway, chains rattle and screams echo. Blood paints the walls and scratch marks cover\n");
          printf("the floor in a trail that leads straight ahead. There is a single torch on the wall that serves as the only source of light. Although \n");
          printf("you can make out the exits, your vision will suffer heavily without a good source of light.\n");
          printf("\n");
          flag1 = 1;
          room2Found = 1;
        }
        printf("Exits: Forward, Backward, Right, Left\n");
      }
      //get user input
      scanf("%s", input);

      if (strcmp(input, commands[0]) == 0){
        for (int i = 0; i < 19; i++){
          printf("%s\n", commands[i]);
        }
        printf("\n");
      }
      else if (strcmp(input, commands[1]) == 0){
        printf("Thank you for playing! Goodbye\n");
        break;
      }
      else if (strcmp(input, commands[2]) == 0){
        playerStats(player.class, player.health, player.armor, player.strength, player.magic, player.speed, player.luck, player.mana);
      }
      else if (strcmp(input, commands[3]) == 0){
        printf("Head: %s\n", equipment[0].name);
        printf("Body: %s\n", equipment[1].name);
        printf("Accessory: %s\n", equipment[2].name);
        printf("Legs: %s\n", equipment[3].name);
        printf("Feet: %s\n", equipment[4].name);
        printf("Right Hand: %s\n", equipment[5].name);
        printf("Left Hand: %s\n", equipment[6].name);
        printf("\n");
      }
      else if (strcmp(input, commands[4]) == 0){
        for (int i = 0; i < 10; i++){
          printf("%s\n", bag[i].name);
        }
      }
      else if (strcmp(input, commands[5]) == 0){
        printf("Which item would you like to equip?\n");
        scanf("%s", itemToEquip);
        for (int i = 0; i < 10; i++){
          if (strcmp(itemToEquip, bag[i].name) == 0){
            if (bag[i].position == 0){
              if (head == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your head. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else if (bag[i].position == 1){
              if (body == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your body. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else if (bag[i].position == 2){
              if (accessory == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped as your accessory. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else if (bag[i].position == 3){
              if (legs == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your legs. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else if (bag[i].position == 4){
              if (feet == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your feet. If you would like to remove it, use the \'Dequip\' command\n");
              }
            }
            else if (bag[i].position == 5){
              if (rHand == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your right hand. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else if (bag[i].position == 6){
              if (lHand == 0){
                printf("You equipped %s!\n", itemToEquip);
                equipment[bag[i].position] = bag[i];
                bag[i] = none;
                break;
              }
              else {
                printf("You already have an item equipped on your left hand. If you would like to remove it, use the \'Dequip\' command.\n");
              }
            }
            else {
              printf("You cannot equip this item.\n");
            }
          }
          else {
            printf("You do not have that item in your bag.\n");
          }
        }
      }
      else if (strcmp(input, commands[6]) == 0){
        printf("Which item would you like to dequip?\n");
        scanf("%s", itemToDequip);
        if (strcmp(itemToDequip, equipment[0].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[0];
            equipment[0] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[0];
            equipment[0] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[0] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[1].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[1];
            equipment[1] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[1];
            equipment[1] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[1] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[2].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[2];
            equipment[2] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[2];
            equipment[2] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[2] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[3].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[3];
            equipment[3] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[3];
            equipment[3] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[3] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[4].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[4];
            equipment[4] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[4];
            equipment[4] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[4] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[5].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[5];
            equipment[5] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[5];
            equipment[5] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[5] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else if (strcmp(itemToDequip, equipment[6].name) == 0){
          if (strcmp(bag[0].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[0] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[1].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[1] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[2].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[2] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[3].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[3] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[4].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[4] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[5].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[5] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[6].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[6] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[7].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[7] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[8].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[8] = equipment[6];
            equipment[6] = none;
          }
          else if (strcmp(bag[9].name, "None") == 0){
            printf("You dequipped %s.\n", itemToDequip);
            bag[9] = equipment[6];
            equipment[6] = none;
          }
          else {
            printf("You do not have any more empy slots in your bag, this means you would drop the item instead. Do you want to drop this item?\n");
            scanf("%s", itemDequipDrop);
            if (strcmp(itemDequipDrop, "Yes") == 0 || strcmp(itemDequipDrop, "yes") == 0){
              printf("You dropped %s.\n", itemToDequip);
              equipment[6] = none;
            }
            else {
              printf("You did not drop nor dequip %s.\n", itemToDequip);
            }
          }
        }
        else {
          printf("You do not have that item equipped.\n");
        }
      }
      else if (strcmp(input, commands[7]) == 0){
        printf("Which item would you like to drop?\n");
        scanf("%s", itemToDrop);
        if (strcmp(itemToDrop, bag[0].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[0] = none;
        }
        else if (strcmp(itemToDrop, bag[1].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[1] = none;
        }
        else if (strcmp(itemToDrop, bag[2].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[2] = none;
        }
        else if (strcmp(itemToDrop, bag[3].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[3] = none;
        }
        else if (strcmp(itemToDrop, bag[4].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[4] = none;
        }
        else if (strcmp(itemToDrop, bag[5].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[5] = none;
        }
        else if (strcmp(itemToDrop, bag[6].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[6] = none;
        }
        else if (strcmp(itemToDrop, bag[7].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[7] = none;
        }
        else if (strcmp(itemToDrop, bag[8].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[8] = none;
        }
        else if (strcmp(itemToDrop, bag[9].name) == 0){
          printf("You dropped %s.\n", itemToDrop);
          bag[9] = none;
        }
        else {
          printf("You do not have that item.\n");
        }
      }
      else if (strcmp(input, commands[8]) == 0){
        printf("Which item would you like to use?\n");
      }
      else if (strcmp(input, commands[9]) == 0){
        printf("Which spell would you like to cast?\n");
      }
      else if (strcmp(input, commands[10]) == 0){
        //attack code
      }
      else if (strcmp(input, commands[11]) == 0){
        //search
      }
      else if (strcmp(input, commands[12]) == 0){
        //forward
        if (x == 0 && y == 0 && z == 0){
          y++;
        }
        else {
          y++;
        }
      }
      else if (strcmp(input, commands[13]) == 0){
        //backward
        if (x == 0 && y == 0 && z == 0){
          printf("The only way is forward.\n");
        }
        else {
          y--;
        }
      }
      else if (strcmp(input, commands[14]) == 0){
        //right
        if (x == 0 && y == 0 && z == 0){
          printf("The only way is forward.\n");
        }
        else {
          x++;
        }
      }
      else if (strcmp(input, commands[15]) == 0){
        //left
        if (x == 0 && y == 0 && z == 0){
          printf("The only way is forward.\n");
        }
        else {
          x--;
        }
      }
      else if (strcmp(input, commands[16]) == 0){
        //up
        if (x == 0 && y == 0 && z == 0){
          printf("The only way is forward.\n");
        }
        else{
          z++;
        }
      }
      else if (strcmp(input, commands[17]) == 0){
        //down
        if (x == 0 && y == 0 && z == 0){
          printf("The only way is forward.\n");
        }
        else {
          z--;
        }
      }
      else if (strcmp(input, commands[18]) == 0){
        for (int i = 0; i < 10; i++){
          if (strcmp(spellbook[i].name, "None") == 0){
            printf("%s\n", spellbook[i].name);
          }
        }
      }
    }
  }
  return 0;
}
//other functions
//stats function
void playerStats(char class[50], int health, int armor, int strength, int magic, int speed, int luck, int mana){
  printf("Class: %s\n", class);
  printf("Health: %d\n", health);
  printf("Armor: %d\n", armor);
  printf("Strength: %d\n", strength);
  printf("Magic: %d\n", magic);
  printf("Speed: %d\n", speed);
  printf("Luck: %d\n", luck);
  printf("Mana: %d\n", mana);
  printf("\n");
}
