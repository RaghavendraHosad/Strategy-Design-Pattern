# Strategy-Design-Pattern
Strategy Design Pattern
An imporatant design pattern. in real life all we do strategy in one or the other time. like for example those who bet in share market, doing startegy while investing
people bargain in market while buying and chooing goods.

In this inplementation there where 3 main entities

1. Context Class
2. Strategy Interface Class - Abstract Base class
3. Concreate class's
4. Client

Context: Essential that evaluates users need () and creats appropriate concreate child class object and assign it to abstract base poit pointer.

Strategy Interface Class is a Abstract Base class having abstract behaviour, those need to be overwritten at concreate child classes.

Concreate class are generalized from base class i.e, from Strategy Interface Class

Client is the main program which creats Context class object and calls behaviour methods.
