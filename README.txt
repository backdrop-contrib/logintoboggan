*******************************************************
    README.txt for logintoboggan.module for Drupal
*******************************************************

This module was co-developed by Jeff Robbins (jjeff) and Chad Phillips (thehunmonkgroup) with several features added by Raven Brook (rbrooks00).

The Login Toboggan module improves the Drupal login system in an external module by offering the following features:

   1. Allow users to login using either their username OR their email address.
   2. Allow users to define their own password during registration.
   3. Allow users to login immediately.
   4. Provide a login form on Access Denied pages for non-logged-in (anonymous) users.
   5. The module provides two login block options: One uses JavaScript to display the form within the block immediately upon clicking "log in". The other brings the user to a separate page, but returns the user to their original page upon login.

Users who choose their own password or log in immediately can be automatically assigned to a selected 'non-authenticated' role. This role could have more permissions than anonymous but less than authenticated - thus preventing spoof accounts and spammers.

The module does NOT require any patches to core or other special configurations.

INSTALLATION:

Put the module in your modules directory.
Enable it.
Done.