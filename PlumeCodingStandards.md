# Introduction #

a rule of thumb:
make your code self-documenting.

# JavaScript coding style guide #

  * use CamelCase for class names
  * use mixedCase for variables, functions, attributes and methods
  * use leading underscore and mixedCase for private members
  * use 4 spaces to indent, not tabs
  * left brackets stay in the same line where an if, while, for or function starts

# Suggested usage #

## Create a class ##
```
var SomeClass = new Class ({

    someProperty: "value", 

    initialize: function (arg1, arg2) {
        // constructor body
    },

    someMethod: function (arg1, arg2) {
        // method body
    }

});
```

## Subclassing ##
```
var SomeSubClass = Class.extend(SomeBaseClass, {
    
    initialize: function () {
        // note there's no means to access either super.initialize() or any other overridden member
    },

    // ...

});
```

## Abstract factory ##
```
var BaseClass = new Class({...});
BaseClass.register = function (implClass) {
    this._impl = implClass;
};
BaseClass.create = function () {
    return new this._impl();
};

var ImplClass = Class.extend(BaseClass, {...});
BaseClass.register(ImplClass);

// avoid creating instances with explicit implementation class names 
var instance = BaseClass.create();
```

## Understanding callbacks ##
```
function doSomeJobAsync(arg1, arg2, callback) {
    var resultValue;
    // ...
    // `callback(resultValue)` will be called somewhere in this function
}

// start doing the job
doSomeJobAsync(1, 2, function (result) {
    // this callback function will be evaluated when the job is done
    // TODO: process the result
});
// async call; job has not been done at this point
```

## Useful jQuery utility functions for coding algorithms ##
```
// iterating an array
$.each(array, function (i, elem) {
    var keepGoing = true;
    // TODO: process the i-th element
    return keepGoing;
});

// filter an array
var newArray = $.grep(array, function (elem) {
    var keep = true;
    // TODO: decide whether the element should be kept in the resulting array
    return keep;
});

// transform an array
var newArray = $.map(array, function (elem) {
    var replaceValue;
    // TODO: make a replace value out of the element
    return replaceValue;
});
```