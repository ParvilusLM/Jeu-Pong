#ifndef DEF_ENUMS
#define DEF_ENUMS

enum{R_JOUEUR1,R_JOUEUR2,R_CPU};
enum{R_DIR_HAUT,R_DIR_BAS,R_DIR_IA};
enum{B_DIR_HG,B_DIR_HD,B_DIR_BG,B_DIR_BD};
enum{CPU,HUMAIN,HUMAIN2};

enum TypeMenu
{
    MenuPrincipal,
    MenuNvlPartie,
    MenuInstructions,
    MenuApropos
};

enum TypeJeu
{
    HUMAINvsHUMAIN,
    HUMAINvsIA
};

enum
{
    AUCUN_EL_ACT,
    NP_ACTIF,
    I_ACTIF,
    AP_ACTIF,
    Q_ACTIF,
    JHvsH_ACTIF,
    JHvsIA_ACTIF,
    R_ACTIF
};



#endif // DEF_ENUMS
