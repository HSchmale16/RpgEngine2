# Requirement Application
... Or how to build up requirement satisfaction groups?

Requirements are defined using the following structure.

    "requirements": [
        {
            "<<<type>>>": "VALUE"
        }
    ]

Requirements are stored as a list of individual conditions that can be met 
to satisfy it.

# Possible things that could be required

* An item,

        "item": "<<<name of item>>>"

* A skill level or attributes. Just about every important metric is stored as 
  an attribute

        "attribute": {
            "name": "<<<name of attribute",
            "min" : "<<<minimum value of attribute", // optional
            "max" : "<<<maximum value of attribute"  // optional
        }

