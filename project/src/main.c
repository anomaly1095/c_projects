#include "../include/_init_.h"

int main(int argc, char **argv){
  // min number of args
  if (argc < 5){
    printf(_USAGE_);
    exit(NO_ARGS);
  }

  _login(argc, argv);
  // _shell();
  return 0x0;
}


void _help(){

}


void _login(_i32 argc, char **argv){
  _ui8 res_p = 00, res_u = 00, *_u, *_p;

  for (_ui8 i = 00; i < argc; ++i){
    if (_str_comp(argv[i], "-u") && i < (_ui8)argc){
      _u = argv[i+1];
      res_u++;
    }
    else if (_str_comp(argv[i], "-p") && i < (_ui8)argc){
      _p = argv[i+1];
      res_p++;
    }
  }
  if (!res_u){
    system("clear");
    printf(_USAGE_);
    exit(U_MISSING);
  }
  if (!res_p){
    system("clear");
    printf(_USAGE_);
    exit(P_MISSING);
  }
  _check_p_u(_p, _u);
}


void _check_p_u(_ui8 *_p, _ui8 *_u) {
  FILE *shadow = fopen("../root/admin/shadow", "r");
  if (shadow == NULL)
    exit(F_NOT_FOUND);

  _ui8 id;
  _ui8 hash[65], u_name[SIZE_U_NAME], pass[SIZE_PASS];

  while (fscanf(shadow, _SHADOW_FORMAT, &id, u_name, pass) == 3) {
    if (_str_comp(_u, u_name) == _SUCCESS) {
      _ui8 enteredHashedPassword[65];
      sha256_hash_string(_p, enteredHashedPassword);
      if (_str_comp(enteredHashedPassword, pass) == _SUCCESS) {
        login_success(_u);
        fclose(shadow);
        return;
      }
    }
  }
  fclose(shadow);
  login_fail();
}


void login_success(_ui8 *_u){
  FILE *_syslogs = fopen("../root/admin/sys_logs.log", "a");
  if (_syslogs == NULL)
    exit(F_NOT_FOUND);
  time_t currentTime;
  time(&currentTime);
  fprintf(_syslogs, "User: %s logged at %s\n", _u, ctime(&currentTime));
  fclose(_syslogs);
}


void login_fail(){
  FILE *_syslogs = fopen("../root/admin/sys_logs.log", "a");
  if (_syslogs == NULL)
    exit(F_NOT_FOUND);
  time_t currentTime;
  time(&currentTime);
  fprintf(_syslogs, "Login attempt failed at: %s.\n", ctime(&currentTime));
  fclose(_syslogs);
  exit(WRONG_CRED);
}