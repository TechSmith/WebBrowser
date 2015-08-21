# WebBrowser
A simple web browser for testing web pages that have OAuth2 logins.

##Setup
You need to make a registry change.  This is so the latest rendering can happen.

So at HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Internet Explorer\Main\FeatureControl\FEATURE_BROWSER_EMULATION
Create a new DWORD (32-bit) value called TechSmithWebBrowser.exe (or whatever you rename this to)
And set the value to the decimal value 11000.

In case you build the 64-bit version do the equilivant registry location but without the Wow6432Node part.

Then you can start up this program.

##Usage
To use should be easy.  Clicking the "Activate Mobile" button can only be pressed once and then to reset you close and reopen
the program.

But it is basically a web browser.
