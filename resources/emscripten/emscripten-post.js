// Move to different directory to prevent save file collisions in IDBFS
FS.mkdir("easyrpg");
FS.chdir("easyrpg");

if (Module.EASYRPG_GAME.length > 0) {
  FS.mkdir(Module.EASYRPG_GAME);
  FS.chdir(Module.EASYRPG_GAME);
}

// Use IDBFS for save file storage when the filesystem was not
// overwritten by a custom emscripten shell file
if (typeof Module.EASYRPG_FS === "undefined") {
  Module.EASYRPG_FS = IDBFS;
}

FS.mkdir("Save");
FS.mount(Module.EASYRPG_FS, {}, "Save");
FS.syncfs(true, function(err) {});
