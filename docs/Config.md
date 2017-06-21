# Configuration of the Game
This file defines how the configuration will work for defining an RPG game.
The configuration of this is very directory oriented. As such the config
directory should look like so:

    config
    \_  itemtypes.json
    \_  locations
    |   \_  ?location1?.json
    |   \_  ?location..n?.json
    \_  items
        \_  ?itemname1?.json
        \_  ?itemname..n?.json

Names in question marks can be any valid name with no spaces.

# Reserved Words
There are certain words that are considered to be reserved for the game. No
entity is allowed to be named as or contain these words in their name in any
case.

* location
* room



## itemtypes.json
There are multiple types of items,
and each type has different valid attributes as defined in 
`config/itemtypes.json`.

The item type definition looks like the below:

    {
        "typename": ["attrib-name1", "attrib-name2", "attrib-name..n"]
    }

An empty array means that that object has no attributes attached to it.

# Items
Items are things that can be placed in inventories and used on various other
entities like furniture and other players.

# Locations
Every location is defined by a json file containing details about the rooms
and a starting room.

A room has the same attributes as any other entity, but it adds doors and
furniture. A piece of furniture is defined as an inventory.

# Calculators
Calculators are special files that allow the engine to load specific
calculations related to an entity. Things like the amount of damage a weapon
can deal.

Calculators are equations written in [Reverse Polish Notation][rpn-calc-example].
A rpn calculator can be found [here][rpn-calc-example]. Except these files can
have variables. These calculators are strictly integer based.

A very basic example might look like the below for calculating how much damage a user
does with melee damage.

    STR ATK * WEP_MOD 100 / 1 +

[rpn-calc-example]: http://www.meta-calculator.com/learning-lab/reverse-polish-notation-calculator.php
[wiki-rpn]: https://en.wikipedia.org/wiki/Reverse_Polish_notation

# Requirements
Certain things can have requirements to interact with them in a certain way. For instance, doors
can require either a key or a certain skill levels. As such the requirement engine is rather
powerful.

Requirements are organized as so:

* RequirementSet
    * RequirementGroup
        * Requirementg