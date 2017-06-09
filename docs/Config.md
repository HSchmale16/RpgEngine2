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
