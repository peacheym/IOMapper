extends Node2D

var dev = GodotMapper.new()
var done = false
var value = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	dev.init("test")
	dev.add_sig("OUT", "test_out", 1, "FLOAT")
	dev.add_sig("IN", "test_in", 1, "FLOAT")
	
	while (!done):
		dev.poll_blocking(10)
		dev.set_value("OUT", 5)

func _process(_delta):
	dev.poll()
	value += 0.5
	dev.set_value("OUT", value)

# Called every frame. 'delta' is the elapsed tisme since the previous frame.
#func _process(delta):
#	pass
