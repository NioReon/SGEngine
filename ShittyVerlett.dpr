program ShittyVerlett;

uses
  Forms,
  Main in 'Main.pas' {ShittyGameEngine},
  _Shader in '_Shader.pas',
  _StrMan in '_StrMan.pas',
  Cameras in 'Cameras.pas',
  dglOpenGL in 'dglOpenGL.pas',
  FontsNew in 'FontsNew.pas',
  PhysicsArifm in 'PhysicsArifm.pas',
  strworks in 'strworks.pas',
  Textures in 'Textures.pas',
  MapStructure in 'MapStructure.pas',
  PhysicsParticles in 'PhysicsParticles.pas',
  ParticleForceGen in 'ParticleForceGen.pas',
  ParticleWorldStructure in 'ParticleWorldStructure.pas',
  PhysicsContacts in 'PhysicsContacts.pas',
  SpawnScripts in 'SpawnScripts.pas',
  PhysicsRigidBody in 'PhysicsRigidBody.pas',
  RigidBodyContacts in 'RigidBodyContacts.pas',
  RigidBodyForceGen in 'RigidBodyForceGen.pas',
  PrimitiveCollsTesters in 'PrimitiveCollsTesters.pas',
  PhysicsMillingtonSolver in 'PhysicsMillingtonSolver.pas',
  GJKCollisions in 'GJKCollisions.pas',
  ShadowCaster in 'ShadowCaster.pas';


begin
  Application.Initialize;
  Application.Title := 'Shitty Game Engine';
  Application.CreateForm(TShittyGameEngine, ShittyGameEngine);
  Application.Run;
end.
