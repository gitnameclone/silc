/* Regex tests */

#include "silc.h"

int main(int argc, char **argv)
{
  SilcBool success = FALSE;
  SilcRegexStruct reg;
  SilcRegexMatchStruct match[10];
  int i, num_match = 10;
  char *regex, *string, *sub;
  SilcBufferStruct bmatch;

  if (argc > 1 && !strcmp(argv[1], "-d")) {
    silc_log_debug(TRUE);
    silc_log_quick(TRUE);
    silc_log_debug_hexdump(TRUE);
    silc_log_set_debug_string("*regex*,*errno*");
  }

  regex = "^a{0}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{0,}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "bbbb";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{0,}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaaaaaaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{0,0}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "a";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;

  regex = "^a{3}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{3}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaa";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;

  regex = "^a{3,5}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{3,5}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{3,5}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaaaa";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;

  regex = "^a{3,}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{3,}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaaaaaaaaaaa";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "^a{3,}$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aa";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;


  regex = "a*b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "b";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "a*b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "ab";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "a*b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaab";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);


  regex = "a+b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "ab";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "a+b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "aaaab";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "a+b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "b";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;


  regex = "ca?b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "cb";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "ca?b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "cab";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex(string, regex, &bmatch, NULL))
    goto err;
  silc_buffer_printf(&bmatch, TRUE);

  regex = "ca?b";
  SILC_LOG_DEBUG(("Regex %s", regex));
  string = "caab";
  SILC_LOG_DEBUG(("DO NOT Match %s", string));
  if (silc_regex(string, regex, &bmatch, NULL))
    goto err;


  regex = "(H..).(o..)";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "Hello World";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex_match(&reg, string, strlen(string), num_match, match, 0))
    goto err;
  for (i = 0; i < num_match; i++) {
    if (match[i].start != -1) {
      SILC_LOG_DEBUG(("Match start %d, end %d", match[i].start,
		      match[i].end));
      sub = silc_memdup(string + match[i].start, match[i].end - 
			match[i].start);
      SILC_LOG_DEBUG(("Match substring '%s'", sub));
      silc_free(sub);
    }
  }

  silc_regex_free(&reg);

  regex = "foo[0-9]*";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "foo";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex_match(&reg, string, strlen(string), 0, NULL, 0))
    goto err;

  string = "foo20";
  SILC_LOG_DEBUG(("Match %s", string));
  if (!silc_regex_match(&reg, string, strlen(string), 0, NULL, 0))
    goto err;

  string = "foo20, bar, foo100, foo";
  SILC_LOG_DEBUG(("Match all substrings in %s", string));
  while (silc_regex_match(&reg, string, strlen(string), 1, match, 0)) {
    SILC_LOG_DEBUG(("Match start %d", match[0].start));
    sub = silc_memdup(string + match[0].start, match[0].end - match[0].start);
    SILC_LOG_DEBUG(("Match substring '%s'", sub));
    silc_free(sub);
    string += match[0].end;
  }

  string = "foo20, bar, foo100, Foo, foo0";
  SILC_LOG_DEBUG(("Match all substrings at once in %s", string));
  if (!silc_regex_match(&reg, string, strlen(string), num_match, match, 0))
    goto err;

  for (i = 0; i < num_match; i++) {
    if (match[i].start != -1) {
      SILC_LOG_DEBUG(("Match start %d", match[i].start));
      sub = silc_memdup(string + match[i].start, match[i].end - 
			match[i].start);
      SILC_LOG_DEBUG(("Match substring '%s'", sub));
      silc_free(sub);
    }
  }

  silc_regex_free(&reg);

  regex = "^(([^:]+)://)?([^:/]+)(:([0-9]+))?(/.*)";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "http://silcnet.org:443/foobar/pelle.html";
  SILC_LOG_DEBUG(("Parse URI"));
  if (!silc_regex_match(&reg, string, strlen(string), num_match, match, 0))
    goto err;

  for (i = 0; i < num_match; i++) {
    if (match[i].start != -1) {
      SILC_LOG_DEBUG(("Match start %d", match[i].start));
      sub = silc_memdup(string + match[i].start, match[i].end - 
			match[i].start);
      SILC_LOG_DEBUG(("Match substring '%s'", sub));
      silc_free(sub);
    }
  }

  string = "http://silcnet.org/";
  SILC_LOG_DEBUG(("Parse URI"));
  if (!silc_regex_match(&reg, string, strlen(string), num_match, match, 0))
    goto err;

  for (i = 0; i < num_match; i++) {
    if (match[i].start != -1) {
      SILC_LOG_DEBUG(("Match start %d", match[i].start));
      sub = silc_memdup(string + match[i].start, match[i].end - 
			match[i].start);
      SILC_LOG_DEBUG(("Match substring '%s'", sub));
      silc_free(sub);
    }
  }

  silc_regex_free(&reg);

  regex = "((a)(b))";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "ab";
  SILC_LOG_DEBUG(("Match all substrings at once in %s", string));
  if (!silc_regex_match(&reg, string, strlen(string), num_match, match, 0))
    goto err;

  for (i = 0; i < num_match; i++) {
    if (match[i].start != -1) {
      SILC_LOG_DEBUG(("Match start %d", match[i].start));
      sub = silc_memdup(string + match[i].start, match[i].end - 
			match[i].start);
      SILC_LOG_DEBUG(("Match substring '%s'", sub));
      silc_free(sub);
    }
  }

  silc_regex_free(&reg);

  regex = "^a";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "a";
  SILC_LOG_DEBUG(("Test NOTBOL flag", string));
  if (silc_regex_match(&reg, string, strlen(string), 0, NULL,
		       SILC_REGEX_NOTBOL))
    goto err;
  if (silc_errno != SILC_ERR_NOT_FOUND)
    goto err;
  SILC_LOG_DEBUG(("Did not match (OK)"));

  silc_regex_free(&reg);

  regex = "a$";
  SILC_LOG_DEBUG(("Regex %s", regex));
  if (!silc_regex_compile(&reg, regex, 0))
    goto err;

  string = "a";
  SILC_LOG_DEBUG(("Test NOTEOL flag", string));
  if (silc_regex_match(&reg, string, strlen(string), 0, NULL,
		       SILC_REGEX_NOTEOL))
    goto err;
  if (silc_errno != SILC_ERR_NOT_FOUND)
    goto err;
  SILC_LOG_DEBUG(("Did not match (OK)"));

  silc_regex_free(&reg);

  success = TRUE;

 err:
  SILC_LOG_DEBUG(("Testing was %s", success ? "SUCCESS" : "FAILURE"));
  fprintf(stderr, "Testing was %s\n", success ? "SUCCESS" : "FAILURE");

  return success;
}
