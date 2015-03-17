# LoginToboggan

The Login Toboggan module improves the Backdrop login system in an external
module by offering the following features:

   1. Allow users to login using either their username OR their email address.
   2. Allow users to login immediately.
   3. Provide a login form on Access Denied pages for non-logged-in
      (anonymous) users.
   4. The module provides two login block options: One uses JavaScript to
      display the form within the block immediately upon clicking "log in".
      The other brings the user to a separate page, but returns the user to
      their original page upon login.
   5. Customize the registration form with two e-mail fields to ensure
      accuracy.
   6. Optionally redirect the user to a specific page when using the
      'immediate login' feature.
   7. Optionally redirect the user to a specific page upon validation of their
      e-mail address.
   8. Optionally display a user message indicating a successful login.
   9. Optionally combine both the login and registration form on one page.
  10. Optionally display a 'Request new password' link on the user login form.
  11. Optionally have unvalidated users purged from the system at a pre-defined
      interval
      (please read the CAVEATS section of INSTALL.txt for important information
       on configuringthis feature!).

Users who choose their own password can be automatically assigned to a selected
'non-authenticated' role. This role could have more permissions than anonymous
but less than authenticated - thus preventing spoof accounts and spammers. The
user will only be removed from the non-authenticated role and granted
authenticated permissions when they verify their account via a special email
link, or when an administrator removes them from the non-authenticated role.

## Installation

Place entire loggintoboggan module folder into
  (a) your sites/all/modules directory
  (b) your sites/[my site]/modules directory.

Enable the module at Administration » Modules

Configure logintoboggan settings at
Administration » Configuration » System » LoginToboggan

The module changes the functionality of the login block AND provides a new
LoginToboggan logged in block'.

Configure each block at Administration » Structure » Blocks as follows...

1. Configure the 'User login' block for LoginToboggan functionality:

Change title if required; using <none> can make for a very neat login system,
when combined with the javascript functionality: clicking upon "Login/register"
reveals the login form in sliding fashion. To select this functionality, select
'Collapsible form' under "Block type". Selecting 'Link' under "Block type"
sends user to a login form, returning them to original page after successful
login.

2. Configure 'LoginToboggan logged in block'

Tip: by leaving the title blank, the 'LoginToboggan logged in block' is slim
and neat.

Done!

## Caveats

1. Use the 'Delete unvalidated users after' feature with extreme caution!

   This feature can be handy, but if misconfigured can cause unexpected damage
   to your user data -- specifically deleting users!  Two things to guard
   against:

     a. Be very careful when editing the 'Non-authenticated role' setting.
        If you set it to anything other than the 'authenticated user' role,
        LoginToboggan will happily start deleting any users you have in that
        role that were created prior to the purge interval. If you want to
        avoid problems, it's best to never change that setting after you've
        initially set it up.

     b. LoginToboggan has mechanisms in place that prevent a user from being
        re-added to the Non-authenticated role after a user has been validated.
        Note that these protections are only present in core's interface -- if
        you have another module enabled which does any role manipulation
        (either via the user interface or programatically), you must find your
        own way to ensure that it doesn't add any users back into the
        Non-authenticated role.

   Also note that the feature is only enabled if the 'Set password' option is
   also enabled.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

## Current Maintainers

-   Jerome Danthinne (https://github.com/jdanthinne/)

## Credits

Co-developed for Drupalby Jeff Robbins (jjeff) and Chad Phillips (hunmonk)
with several features added by Raven Brooks (rbrooks00).