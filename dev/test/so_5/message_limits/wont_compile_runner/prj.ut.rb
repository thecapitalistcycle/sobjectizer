require 'mxx_ru/binary_unittest'

path = 'test/so_5/message_limits/wont_compile_runner'

MxxRu::setup_target(
	MxxRu::BinaryUnittestTarget.new(
		"#{path}/prj.ut.rb",
		"#{path}/prj.rb" )
)
