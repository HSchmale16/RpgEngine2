# Requirement Application
... Or how to build up requirement satisfaction groups?

Requirements are defined using the following structure.

    "requirements": [
        [
            {
                "requirementType": "item | attribute",
                "name": "name of item or name of attribute"
            }
        ]
    ]

Requirements are stored as a list of individual conditions that can be met 
to satisfy it.

# Possible things that could be required to interact

*   Target has a specific item by name in inventory,

        {
            "requirementType": "item",
            "name": "<<< name of item >>>"
        }

*   A skill level or attributes. Just about every important metric is stored as
    an attribute

        {
            "requirementType": "attribute",
            "name": "<<< name of attribute >>>",
            "min" : "<<< minimum value of attribute >>>", // assumed to be greater than 0
            "max" : "<<< maximum value of attribute >>>"  // optional not inclusive
        }

    if `min` and `max` are the same then it is assumed that the attribute must
    merely exist, and not be the default value, which is the lowest possible
    value for an `AttributeInteger`. Otherwise the value of the attribute
    must be [min,max] to use interval notation.
    

# Structure of Classes used to implement requirements