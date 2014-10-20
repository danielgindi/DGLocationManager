DGLocationManager
=================

A singleton Location Manager as a replacement for `CLLocationManager` (iOS / ObjC)

If you are tired of instantiating `CLLocationManager` all over the place, then this one is for you. It will act as a singleton, and will also cache the last location/direction available.

The library is thread-safe, no need to instantiate the class, there's a multi-delegate mechanism so you can add as many delegates as you like.

Note: The location manager will start the internal `CLLocationManager` as soon as you add your first delegate, and will stop it when you remove the last one.


This was originally in my other repository https://github.com/danielgindi/drunken-danger-zone/


## Me
* Hi! I am Daniel Cohen Gindi. Or in short- Daniel.
* danielgindi@gmail.com is my email address.
* That's all you need to know.

## Help

If you like what you see here, and want to support the work being done in this repository, you could:
* Actually code, and issue pull requests
* Spread the word
* 
[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=CHRDHZE79YTMQ)

## License

All the code here is under MIT license. Which means you could do virtually anything with the code.
I will appreciate it very much if you keep an attribution where appropriate.

    The MIT License (MIT)
    
    Copyright (c) 2013 Daniel Cohen Gindi (danielgindi@gmail.com)
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
