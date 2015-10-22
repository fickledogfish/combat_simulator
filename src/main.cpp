#include <iostream>

#include "random.hpp"
#include "Army.hpp"
#include "Turn.hpp"

// draconic constants
const int DRAGON_HEALTH = 300;
const int DRAGON_DAMAGE = 100;
const int DRAGON_DAMAGE_CHANCE = 40;
// L'or... elvish constants
const int ELF_HEALTH = 150;
const int ELF_DAMAGE = 100;
const int ELF_DAMAGE_CHANCE = 70;

int main() {

    bool verbose = false;

    int elf_army_size;
    int dragon_army_size;

    std::cout << "How many dragons are there? ";
    std::cin >> dragon_army_size;
    std::cout << "How many elves are there? ";
    std::cin >> elf_army_size;

    std::cout << std::endl;

    std::cout << "Starting simulation..." << std::endl;

    // declare the two armies
    army::Army elves {elf_army_size, ELF_HEALTH, ELF_DAMAGE, ELF_DAMAGE_CHANCE, elf_army_size, ELF_HEALTH};
    army::Army dragons {dragon_army_size, DRAGON_HEALTH, DRAGON_DAMAGE, DRAGON_DAMAGE_CHANCE, dragon_army_size, DRAGON_HEALTH};

    // randomize the first player (50% chance for each)
    int roll_starter = rnd::random_int(1, 100);

    // create the turn
    turn::Turn turner { (roll_starter < 50)? turn::CurrentTurn::DRAGON : turn::CurrentTurn::ELF };

    while(elves.living_components > 0 && dragons.living_components > 0) {

        // roll the attack percentage
        int roll_attack = rnd::random_int(1, 100);

        switch (turner.player) {
            case turn::CurrentTurn::DRAGON:
                if (roll_attack <= dragons.damage_chance)
                    elves.current_health_points -= dragons.damage;

                // if the dragon kill the elf, reset life and declare deceased
                if (elves.current_health_points <= 0) {
                    elves.living_components--;
                    elves.current_health_points = ELF_HEALTH;
                    if (verbose)
                        std::cout << "Dead elf!" << std::endl;
                }
                break;
            case turn::CurrentTurn::ELF:
                if (roll_attack <= elves.damage_chance)
                    dragons.current_health_points -= elves.damage;

                // if the elf kill the dragon, reset life and declare deceased
                if (dragons.current_health_points <= 0) {
                    dragons.living_components--;
                    dragons.current_health_points = DRAGON_HEALTH;
                    if (verbose)
                        std::cout << "Dead dragon!" << std::endl;
                }
                break;
            default:
                std::cout << "ERROR: unexpected turn owner." << std::endl;
                return -1;
        }

        turner.switch_turn();
    }

    std::cout << "Simulation ended successfully." << std::endl;

    // compute the results and show it
    if (elves.living_components == 0) {
        std::cout << "Dragons have won! " << dragons.living_components << " still live!" << std::endl;
    } else if (dragons.living_components == 0) {
        std::cout << "Elves have won! " << elves.living_components << " still live!" << std::endl;
    }

    return 0;
}
