# Intro #

The web IME **Plume.js** is a DHTML app with static data files, mainly written in JavaScript and GWT.

# Dev tools #

  * JDK 1.6+

  * Python 2.6

  * Eclipse, Subclipse plugin, Google Eclipse Plugin (shipped with GWT SDK 2.0)

  * Firefox 3.5+, Firebug plugin

  * jQuery.js (already included in the project source)

# Setup #

  * checkout project from svn repo:
    * ` https://zime.googlecode.com/svn/trunk/plume `
    * see [Checkout Instructions](http://code.google.com/p/zime/source/checkout) for your password

  * make data files:
```
cd plume/data
python make-json.py -v -s pinyin
python make-json.py -v -s jyutping
```
> > the resulting JSON files are under the directory ` plume/war/data `

  * launch GWT Development Mode

  * load Plume.html in your browser. you'll be prompted to install a GWT dev mode plugin.

  * voila!