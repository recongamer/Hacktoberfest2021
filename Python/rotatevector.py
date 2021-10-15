from manim import *
class RotateVector(Scene):
    def construct(self):
        coord_start=[1,1,0]
        coord_end=[2,3,0]
        dot_start=Dot().move_to(coord_start)
        dot_end=Dot().move_to(coord_end)
        vector=Arrow(coord_start,coord_end,buff=0)
        vector.set_color(RED)

        self.add(dot_start,dot_end)
        self.play(GrowArrow(vector))

        self.play(
            Rotating(
                        vector,
                        radians=PI*2,
                        about_point=coord_start,
                        rate_func=smooth,
                        run_time=1
                    )
        )
        self.wait()
        self.play(
            Rotating(
                        vector,
                        radians=PI*2,
                        about_point=coord_end,
                        rate_func=linear,
                        run_time=1
                    )
        )
        self.wait()
