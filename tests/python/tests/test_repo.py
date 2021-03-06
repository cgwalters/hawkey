#
# Copyright (C) 2012-2013 Red Hat, Inc.
#
# Licensed under the GNU Lesser General Public License Version 2.1
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
#

import unittest

import hawkey

class Package(unittest.TestCase):
    def test_create(self):
        r = hawkey.Repo("fog")
        self.assertIsNotNone(r)
        self.assertRaises(TypeError, hawkey.Repo);
        self.assertRaises(TypeError, hawkey.Repo, 3)
        self.assertRaises(TypeError, hawkey.Repo, rain="pouring")

    def test_cost_assignment(self):
        r = hawkey.Repo("fog", cost=500)
        self.assertEqual(500, r.cost)
        r.cost = 300
        self.assertEqual(300, r.cost)
        r2 = hawkey.Repo("blizzard")
        self.assertEqual(1000, r2.cost)
