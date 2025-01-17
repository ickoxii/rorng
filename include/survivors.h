#ifndef _SURVIVORS_H
#define _SURVIVORS_H

#include <stdlib.h>

#define MAX_ABILITIES 4

typedef struct {
  const char *primary[MAX_ABILITIES];
  const char *secondary[MAX_ABILITIES];
  const char *utility[MAX_ABILITIES];
  const char *special[MAX_ABILITIES];
} Abilities;

typedef struct {
  const char *name;
  Abilities abilities;
} Survivor;

Survivor survivors[] = {
  {
    "Commando",
    {
      {"Double Tap", NULL},
      {"Phase Round", "Phase Blast", NULL},
      {"Tactical Dive", "Tactical Slide", NULL},
      {"Suppressive Fire", "Frag Grenade", NULL},
    },
  },

  {
    "Huntress",
    {
      {"Strafe", "Flurry", NULL},
      {"Laser Glaive", NULL},
      {"Blink", "Phase Blink", NULL},
      {"Arrow Rain", "Ballista", NULL},
    },
  },

  {
    "Bandit",
    {
      {"Burst", "Blast", NULL},
      {"Serrated Dagger", "Serrated Shiv", NULL},
      {"Smoke Bomb", NULL},
      {"Lights Outs", "Desperado", NULL},
    },
  },

  {
    "MUL-T",
    {
      {"Auto-Nailgun", "Rebar Puncher", "Scrap Launcher", "Power-Saw"},
      {"Blast Canister", NULL},
      {"Transport Mode", NULL},
      {"Retool", "Power Mode", NULL},
    },
  },

  {
    "Engineer",
    {
      {"Bouncing Grenades", NULL},
      {"Pressure Mines", "Spider Mines", NULL},
      {"Bubble Shield", "Thermal Harpoons", NULL},
      {"TR12 Gauss Auto-Turret", "TR58 Carbonizer Turret", NULL},
    },
  },

  {
    "Artificer",
    {
      {"Flame Bolt", "Plasma Bolt", NULL},
      {"Charged Nano-Bomb", "Cast Nano-Spear", NULL},
      {"Snapfreeze", NULL},
      {"Flamethrower", "Ion Surge", NULL},
    },
  },

  {
    "Mercenary",
    {
      {"Laser Sword", NULL},
      {"Whirlwind", "Rising Thunder", NULL},
      {"Blinding Assault", "Focused Assault", NULL},
      {"Eviscerate", "Slicing Winds", NULL},
    },
  },

  {
    "REX",
    {
      {"DIRECTIVE: Inject", NULL},
      {"DIRECTIVE: Drill", "Seed Barrage", NULL},
      {"DIRECTIVE: Disperse", "Bramble Volley", NULL},
      {"DIRECTIVE: Harvest", "Tangling Growth", NULL},
    },
  },

  {
    "Loader",
    {
      {"Knuckleboom", NULL},
      {"Grapple Fist", "Spiked Fist", NULL},
      {"Charged Gauntlet", "Thunder Gauntlet", NULL},
      {"M551 Pylon", "Thunderslam", NULL},
    },
  },

  {
    "Acrid",
    {
      {"Vicious Wounds", NULL},
      {"Neurotoxin", "Ravenous Bite", NULL},
      {"Caustic Leap", "Frenzied Leap", NULL},
      {"Epidemic", NULL},
    },
  },

  {
    "Captain",
    {
      {"Vulcan Shotgun", NULL},
      {"Power Tazer", NULL},
      {"Orbital Probe", "OGM-72 'DIABLO' Strike", NULL},
      {"Beacon: Healing", "Beacon: Shocking", "Beacon: Resupply", "Beacon: Hacking"},
    },
  },

  {
    "Railgunner",
    {
      {"XQR Smart Round System", NULL},
      {"M99 Sniper", "HH44 Marksman", NULL},
      {"Concussion Device", "Polar Field Device", NULL},
      {"Supercharged Railgun", "Cryocharged Railgun", NULL},
    },
  },

  {
    "「V??oid Fiend』",
    {
      {"【D??row?n」", NULL},
      {"『Floo?d」", NULL},
      {"「?Tr?espass】", NULL},
      {"【Sup??ress』", NULL},
    },
  },

  {
    "Seeker",
    {
      {"Spirit Punch", NULL},
      {"Unseen Hand", "Soul Spiral", NULL},
      {"Sojourn", NULL},
      {"Meditate", NULL},
    },
  },

  {
    "False Son",
    {
      {"Club of the Forsaken", NULL},
      {"Lunar Spikes", NULL},
      {"Step of the Brothers", NULL},
      {"Laser of the Father", "Laser Burst", NULL},
    },
  },

  {
    "Chef",
    {
      {"Dice", NULL},
      {"Sear", NULL},
      {"Roll", NULL},
      {"Glaze", "Yes, Chef!", NULL},
    },
  },
};

#endif
