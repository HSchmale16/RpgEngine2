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

* An item,

        {
            "requirementType": "item",
            "name": "<<< name of item >>>"
        }

* A skill level or attributes. Just about every important metric is stored as 
  an attribute

        {
            "requirementType": "attribute",
            "name": "<<< name of attribute >>>",
            "min" : "<<< minimum value of attribute >>>", // optional
            "max" : "<<< maximum value of attribute >>>"  // optional
        }

# 