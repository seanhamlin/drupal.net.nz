core = 7.x
api = 2
projects[addressfield] = 1.0-beta3
projects[addressfield][type] = module
projects[addressfield][subdir] = contrib

; State field not required by NZ
projects[addressfield][patch][] = "http://drupal.org/files/addressfield-NZ_formats-1651612-20.patch"
; Views integration
projects[addressfield][patch][] = "http://drupal.org/files/addressfield-additional_views_fieldformatters-991834-41.patch"
