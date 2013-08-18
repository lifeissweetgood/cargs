cargs
=====

C Implementation of Args Parser from "Clean Code" (http://codingdojo.org/cgi-bin/wiki.pl?KataArgs)

To compile, run make.

To run:

    $ ./parser [args]
    ex: $ ./parser -l -p 8080 -d /usr/logs/
    (Result)
        Logging: true
        Port: 8080
        Directory: /usr/logs
    ex: $ ./parser -l -p 80 -d ~/src/ -g hello -n 1,-5,19,3 -s this,is,a,list
    (Result)
        Logging: true
        Port: 80
        Directory: ~/src/
        StrList:
                this
                is
                a
                list
        CharList:
                h
                e
                l
                l
                o
        NumList:
                1
                -5
                19
                3
