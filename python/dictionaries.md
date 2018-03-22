## Mappings and dictionaries
Many algorithms need to map a key to a data value. This kind of mappin is supported by the Python dictionary, dict.
We are in the posiion to look at two applicaiotns of the dicionary. we will look at thow python uses dictionaries along with sequencs to handles arbitarary connecitons of parrameters to funcitons in Advanced Parameter handling for Fucnitons. thi sis a very sophoiticated set of tools that let us define funcitons that are very flexible and essya to use.

## Dictionary Semantics
A dictionary, called a dict, maps a key to a vlaue. the key can be any types of Python object that computes a consistent hash value. the value referenced by the key can be any type of Python objet.

There is a subtile terminology issue here. Pyhton has provisions for creatin a variety of different types of mappings. only one type of mappng comes built0-in; that type is the dict. the terms are almost interchagneable. however, you may develop or doenload other types of mappings, so we will be carefu to focus on the dict class.

## Some Alternate terminology
A dict can be called an associate array. ordinary arrays, typified by sequences, use a numeric index, but a dict's index is made up of hte key objects. Each key is associated with or mapped to the appropriate value.

## Some Consequences
Each key object has a hash value, which is used to place the value in the dict. Consequently, the keys must have consistent hsh values; they must be immutable objects. You can't use list, dict or set objects as keys. you can use tuple, string and forzenset objects, since they are immutable. Additionally, when we get to class defiinitions, we can make arrangements for our objects to return an immutable hash value.

A common programming need is a heterogenous container of data. databse record are an example. A record in a database might have a boat's name, the length overall and an inventory of sails. Often a record like this will have each element identified by name.

A c or c++ struct acoompoishes this. this kind of named collection fo data elements may be better handled with a class or a named tupled. however, a mapping is also useful for managing this kind of heterogernous data with named fields.

note that many languages make record definitions a staticallydefined container of named fields.

## Dictionary Literal values
A dict literal is created by surronding a key-value list with {}; a key is separated from its value with :, and the key value pairs are separated with commans, an empty dict is simply {}. As with list and tuple, an extra, inside the the {} is tolerated.

## Strubg formatting with Dictionaries
The string fromatting operator, %, can be applied betweeen str and dict as well as str and sequnce. When this operator was introduced in Stirngs, the format specifications were applied to a tuple or other sequnces. When used with a dict, each format specification is given an additional option that specifies which dict element to use. the general fromat for each conversion specificaiotn

## Dictionary comparison operations
Some of the standard coparisons don't have a lot of meaning between two dictionaries. Since there may be no common keys, nor even a common data tyupe for keys, dictionaries are simply compared by length. the dict with fewer elements is considered less than a dict with more elements.
