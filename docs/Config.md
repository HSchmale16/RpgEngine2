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

# Items
Items are things that can be placed in inventories and used on various other
entities like furniture and other players.

## itemtypes.json
There are multiple types of items,
and each type has different valid attributes as defined in 
`config/itemtypes.json`.

The item type definition looks like the below:

    {
        "typename": ["attrib-name1", "attrib-name2", "attrib-name..n"]
    }

An empty array means that that object has no attributes attached to it.


# Locations
Every location is defined by a json file containing details about the rooms
and a starting room.

A room has the same attributes as any other entity, but it adds doors and
furniture. A piece of furniture is defined as an inventory.