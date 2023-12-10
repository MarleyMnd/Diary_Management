# DIARY MANAGEMENT

***

## Aim:

This program creates **level lists** using C language. It measures the time taken to look for a value in a level list using two different methods.

- Dichotomic search
- Linear search

***

## Recommendations:

We recommend not to exceed 15 levels (= 32768 nodes) for the level list.

We tested for 16 levels (= 65535 nodes): the complete run took over 40 minutes for 10000, 100000 and 1000000 searches.

***

- Example for 3 levels:

>`[list head_1 @-]-->[ 1|@-]-->[ 2|@-]-->[ 3|@-]-->[ 4|@-]-->[ 5|@-]-->[ 6|@-]-->[ 7|@-]--> NULL`
>
>`[list head_2 @-]------------>[ 2|@-]------------>[ 4|@-]------------>[ 6|@-]------------> NULL`
>
>`[list head_3 @-]-------------------------------->[ 4|@-]--------------------------------> NULL`


-  Example for 4 levels (_zoom out for alignment_):

>`[list head_1 @-]-->[ 1|@-]-->[ 2|@-]-->[ 3|@-]-->[ 4|@-]-->[ 5|@-]-->[ 6|@-]-->[ 7|@-]-->[ 8|@-]-->[ 9|@-]-->[ 10|@-]-->
[ 11|@-]-->[ 12|@-]-->[ 13|@-]-->[ 14|@-]-->[ 15|@-]--> NULL`
>
>`[list head_2 @-]------------>[ 2|@-]------------>[ 4|@-]------------>[ 6|@-]------------>[ 8|@-]------------>[ 10|@-]---
--------->[ 12|@-]------------>[ 14|@-]------------> NULL`
>
>`[list head_3 @-]-------------------------------->[ 4|@-]-------------------------------->[ 8|@-]------------------------
-------->[ 12|@-]----------------------------------------------------> NULL`
>
>`[list head_4 @-]------------------------------------------------------------------------>[ 8|@-]------------------------
------------------------------------------------> NULL`

***

## How to use it:

1. Compile the program and run it.
2. Follow the steps on the screen:
- Enter the number of levels you want to create (number of cells will be automatically computed).
- Choose to display the arrays (values and levels of the cells) or not.
- Choose a format for the list to be printed in.
- Choose a value to look for.
- Enter 3 integers (separated by a space) to define the number of searches to perform.

***

## Example of output:

> Enter the max number of levels of the list (1-15 max. recommended): `3`
> 
> Display arrays (value / level) ? (1/0): `0`
> 
> Head inserted. \
> Insertion finished.
>
> Formats :
> 
> 0. Do not display the list
> 1. Aligned
> 2. Not aligned
> 
> `1` 
>
>>`[list head_1 @-]-->[ 1|@-]-->[ 2|@-]-->[ 3|@-]-->[ 4|@-]-->[ 5|@-]-->[ 6|@-]-->[ 7|@-]--> NULL`
>>
>>`[list head_2 @-]------------>[ 2|@-]------------>[ 4|@-]------------>[ 6|@-]------------> NULL`
>>
>>`[list head_3 @-]-------------------------------->[ 4|@-]--------------------------------> NULL`
> 
> Enter a value to look for: `4`
> 
> Enter 3 integers (separated by a space) to define the number of searches to perform: 
> 
>`10000 500000 2000000`
> 
>
> 
> Dichotomic search : The value 6 is found. \
> Time taken to search 1000000 times: **[0]ms 0,007s**
> 
> Simple search : The value 6 is found in first line.\
> Time taken to search 1000000 times: **[0]ms 0,009s**
> 
> 
> Dichotomic search : The value 6 is found.\
> Time taken to search 10000000 times: **[0]ms 0,054s**
> 
> Simple search : The value 6 is found in first line.\
> Time taken to search 10000000 times: **[0]ms 0,101s**
> 
> 
> Dichotomic search : The value 6 is found.\
> Time taken to search 100000000 times: **[0]ms 0,574s**
> 
> Simple search : The value 6 is found in first line.\
> Time taken to search 100000000 times: **[0]ms 1,025s**

Please note that for level list containing more than 15 levels (= 32768 nodes), you **shouldn't exceed 10000000 searches**, otherwise the program will take too much time to run (**around 20 minutes**).