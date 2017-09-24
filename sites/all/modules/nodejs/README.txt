Node.js integration
===================

This module adds Node.js integration to Drupal. It provides an API that other
modules can use to add realtime capabilities to Drupal, such as push
notifications or chat. The module relies on a Node.js server application that
maintains an open connection with the visitor's browser to enable instant
communication. In order to use this module, you will need to install the Node.js
application on a server.

Installation
============

1. Install Node.js on your server, if not installed yet. Download the installer
   and follow the instructions on the Node.js website:
   https://nodejs.org/en/download/

2. Install the drupal-node.js server application and ensure that the application
   is running. Follow the instruction on GitHub:
   https://github.com/beejeebus/drupal-nodejs

3. Install and enable the Node.js integration Drupal module on your site.

4. Visit the Node.js configuration page under the Configuration menu, and enter
   the connection information for your Node.js server application. The protocol,
   port, and service key settings should match the settings you entered in the
   config file of the Node.js server application. The host should be set to the
   hostname of the server on which you installed the Node.js server application.
   This host needs to be publicly accessible (i.e. "localhost" will not work).

5. Visit the status page of your Drupal site and ensure that there are no
   errors. Node.js should report that it has successfully connected to the
   Node.js server.

Note: The Drupal module and Node.js server application are sensitive to version
numbers. Ensure that you are running the latest version of both. The Drupal
status page will show an error if the versions are not compatible.
